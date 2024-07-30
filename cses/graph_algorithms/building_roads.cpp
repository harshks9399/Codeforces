// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void dfs(int index, vector<int>&check, map<int,vector<int>>&par){
    check[index]=1;
    for(int it:par[index]){
        if(check[it]==1) continue;
        dfs(it,check,par);
    }
}

void solve(){
    int n,k;cin>>n>>k;
    map<int,vector<int>>par;
    while(k--){
        int a,b;cin>>a>>b;
        par[a].push_back(b);
        par[b].push_back(a);
    }

    vector<int>roads;
    vector<int>check(n+1);
    dfs(1,check,par);

    for(int i=2;i<=n;i++){
        if(check[i]==1) continue;
        par[i].push_back(1);
        par[1].push_back(i);
        roads.push_back(i);
        dfs(i, check, par);
    }
    cout<<roads.size()<<"\n";
    for(int it:roads){
        cout<<1<<" "<<it<<"\n";
    }
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}