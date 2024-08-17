/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 09:09:58
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
map<int,vector<int>>m;
// map<int,int>s1,s2;
int N = 2e5+1;
vector<int>s1(N,0), s2(N,0);


void dfs(int index,int par=-1){
    bool child = false;
    int temp = 0;
    s2[index] = 0;
    for(int it:m[index]){
        if(it==par) continue;
        child = true;
        dfs(it,index);
        s2[index] += max(s1[it], s2[it]);
    }
    if(!child) return;
    s1[index] = INT_MIN + 2;
    for(int it: m[index]){
        if(it==par) continue;
        s1[index] = max(s1[index], 1 + s2[index] + s2[it] - max(s2[it],s1[it]));
    }
}
void solve(){
    int n;
    cin>>n;
    m.clear();
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    // s1.clear();
    // s2.clear();
    dfs(1);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<s1[i]<<" "<<s2[i]<<"\n";
    // }
    cout<<max(s1[1], s2[1])<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}