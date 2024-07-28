// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int MOD = 1e9+7;

void solve(){
    lli n;cin>>n;

    vector<lli>dp(1,0);
    for(int i=1;i<=n;i++){
        lli x = 0;
        if(i<=6) x = 1;
        for(int j=i-1;j>=0 && j>=i-6;j--){
            x = (x+dp[j])%MOD;
        }
        dp.push_back(x);
    }
    // cout<<it<<" ";
    // cout<<"\n";
    cout<<dp[n];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}