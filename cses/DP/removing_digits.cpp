// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int solve_dp(int n, vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    vector<int>dig;
    int a = n;
    while(a!=0){
        dig.push_back(a%10);
        a = a/10;
    }
    dp[n] = 1e9;
    for(int it:dig){
        if(n-it<0) continue;
        dp[n] = min(dp[n], solve_dp(n-it,dp)+1);
    }
    return dp[n];
}

void solve(){
    int n;cin>>n;
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    int ans = solve_dp(n, dp);
    cout<<ans;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}