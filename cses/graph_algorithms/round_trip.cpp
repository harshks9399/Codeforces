// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void dfs(int index, vector<int>&check_all, vector<int>&check, map<int,vector<int>>&edge, stack<int>&progress, int par){

    

}



void solve(){
    int n,m;
    cin>>n>>m;
    map<int,vector<int>>edge;
    while(m--){
        int x,y;cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    int ans  = 0;
    vector<int>check_all(n+1);
    vector<int>check(n+1);
    stack<int>progress;


    for(int i=1;i<=n;i++){
        if(ans==1) break;
        if(check_all[i]==1) continue;

        
        dfs(i, check_all, check, edge, progress,-1 );


    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}