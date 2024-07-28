// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
vector<vector<int>>dp(501,vector<int>(501,-1));

int solve_dp(int n, int m){
    if (dp[n][m]!=-1) return dp[n][m];
    if(n < m) return dp[n][m] = solve_dp(m,n);
    dp[n][m] = INT_MAX;
    for(int i=1;i<n;i++)
        dp[n][m] = min(dp[n][m], 1 + solve_dp(i,m) + solve_dp(n-i, m));
    
    for(int i=1;i<m;i++)
        dp[n][m] = min(dp[n][m], 1 + solve_dp(n,i) + solve_dp(n, m-i));
    
    return dp[n][m];
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=500;i++) dp[i][i] = 0;
    for(int i=2;i<=500;i++) dp[1][i] = i-1;  
    int ans  = solve_dp(n,m);
    cout<<ans<<"\n";
}
//
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}