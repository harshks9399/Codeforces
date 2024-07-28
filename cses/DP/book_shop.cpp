// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,x;cin>>n>>x;
    vector<int>pri(n),pag(n);
    for(int i=0;i<n;i++) cin>>pri[i];
    for(int i=0;i<n;i++) cin>>pag[i];

    vector<vector<lli>>dp(2,vector<lli>(x+1,0));
    //1 book;
    for(int i=0;i<=x;i++) if(i>=pri[0]) dp[0][i] = pag[0];

    for(int i=1;i<n;i++){
        dp[1] = dp[0];
        for(int j=0;j<=x;j++){
            if(j>=pri[i] ) dp[1][j] = dp[1][j] > (pag[i] + dp[0][j-pri[i]]) ? dp[1][j] : (pag[i] + dp[0][j-pri[i]]); 
        }
        dp[0] = dp[1];
    }
    cout<<dp[0][x];
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}