// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1));
    
    for(int i=0;i<=n1;i++) dp[i][0] = i;
    for(int i=0;i<=n2;i++) dp[0][i] = i;


    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            dp[i][j] = dp[i-1][j-1];
            if(s1[i-1]!=s2[j-1]) dp[i][j]++;
            dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);
            dp[i][j] = min(dp[i-1][j] + 1, dp[i][j]);
        }
    }
    // cout<<"dp\n";
    // for(auto it:dp){
    //     for(int it1:it) cout<<it1<<" ";
    //     cout<<"\n";
    // }

    cout<<dp[n1][n2];


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}