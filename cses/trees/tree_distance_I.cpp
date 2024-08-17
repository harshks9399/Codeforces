/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 10:30:38
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int N = 2e5 + 1;
vector<vector<int>>m(N, vector<int>());
void dfs(int index, int par, vector<int>&dist){
    for(int it:m[index]){
        if(it==par) continue;
        dist[it] = 1+ dist[index];
        dfs(it,index,dist);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    vector<int>dist(n+1,0), dist1(n+1,0);
    dfs(1,-1,dist);
    int max1 = ( max_element(dist.begin(), dist.end()) - dist.begin() );
    for(int i=1;i<=n;i++) dist[i] = 0;
    dfs(max1, -1, dist);
    int max2 = ( max_element(dist.begin(), dist.end()) - dist.begin() );
    dfs(max2, -1, dist1);
    // cout<<max1<<"\n";
    for(int i=1;i<=n;i++)
    cout<<max(dist[i], dist1[i])<<" ";
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