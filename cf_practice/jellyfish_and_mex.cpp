// THE BASIC SNIPPET
// We have template for fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<int>v(n);
    unordered_map<int,int>m;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        m[x]++;
    }

    int N = 1e9+1;
    int missing = -1;
    for(int i=0;i<=N;i++) {
        if(m.find(i)!=m.end()) continue;
        missing  = i;
        break;
    }

    if(missing == 0 || m[0]==1){
        cout<<0<<"\n";
        return;
    }
    vector<lli>dp(missing+1,-1);
    //dp[i] -> cost when MEX(arr) = i;

    dp[0] = 0;
    dp[1] = (m[0]-1);
    for(int i=2;i<=missing;i++){
        // dp[2] - > MEX = 2
        dp[i] = (m[0]-1)*i;
        for(int j=i-1;j>0;j--){
            lli alt = (m[j]-1)*i + j + dp[j];
            dp[i] = dp[i] < alt ? dp[i] : alt;
        }
    }
    cout<<dp[missing]<<"\n";
    // for(auto it:dp) cout<<it<<" ";
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