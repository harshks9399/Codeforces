/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 09:02:24
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

map<int,int>score;
map<int,vector<int>>m;

void dfs(int index){
    int temp = 0;
    for(int it:m[index]){
        dfs(it);
        temp += 1 + score[it];
    }
    score[index] = temp;
}
void solve(){
    int n;
    cin>>n;
    m.clear();
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        m[x].push_back(i);
    }
    score.clear();
    dfs(1);
    for(auto it:score) cout<<it.second<<" ";
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}