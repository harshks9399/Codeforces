/*
 Author : Harsh Kumar Singh
 created at : 2024-08-15 20:33:54
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,q;
    cin>>n>>q;
    map<char, multiset<int>>temp1;
    map<int, multiset<char>>temp2;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        temp1[a].insert(i);
        temp1[b].insert(j);
        temp2[i].insert(a);
        temp2[i].insert(b);
    }

    vector<vector<lli>>dist(n , vector<lli>(n, INT_MAX));
    for(int i=1;i<=n;i++) dist[i][i] = 0;

    

    while(q--){
        int x,y;
        cin>>x>>y;
        
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}