/*
 Author : Harsh Kumar Singh
 created at : 2024-08-23 21:02:13
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &it : v) cin>>it;
    vector<int>dp(n);
    dp[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--){
        int h = v[i];
        if(h >= n-i) dp[i] = h;
        else dp[i] = h + dp[i + h];
    }
    cout<<*max_element(dp.begin(), dp.end())<<"\n";
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