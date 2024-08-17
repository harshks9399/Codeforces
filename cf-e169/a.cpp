/*
 Author : Harsh Kumar Singh
 created at : 2024-08-15 20:07:41
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &it : v) cin>>it;
    if(n==2){
        if(abs(v[0]-v[1])==1) cout<<"NO\n";
        else cout<<"YES\n";
        return;
    } 
    cout<<"NO\n";
    return;
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