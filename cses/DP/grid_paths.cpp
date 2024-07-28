// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1e9+7;

void solve(){
    int n;cin>>n;
    vector<vector<int>>grid(n, vector<int>(n));
    for(int i=0;i<n*n;i++){
        char a;
        cin>>a;
        if(a=='*') grid[i/n][i%n] = 1;
    }
    if(grid[n-1][n-1]==1){
        cout<<"0";
        return;
    }
    vector<vector<int>>dp(n,vector<int>(n));
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==n-1 && j==n-1){
                dp[i][j] = 1;
                continue;
            }
            if(grid[i][j]==1) continue;
            if(i==n-1) dp[i][j] = dp[i][j+1];
            else if(j==n-1) dp[i][j] = dp[i+1][j];
            else dp[i][j] = (dp[i+1][j] + dp[i][j+1])%mod;
        }
    }
    cout<<dp[0][0];

    // cout<<"\ndp\n";
    // for(auto it:dp){
    //     for(int it1:it) cout<<it1<<" ";
    //     cout<<"\n";
    // }

    return; 

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}