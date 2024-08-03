// THE BASIC SNIPPET
// We have template for fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    map<lli,lli>m1,m2; //prefix sum
    vector<lli>pre;
    pre.push_back(0);
    lli curr =0;
    for(int i=0;i<n;i++){
        curr += a[i];
        pre.push_back(curr);
        m1[curr] = i;
        m2[i+1] = curr;
    }
    m2[0] = 0;

    vector<int>dp(n);
    dp[n-1] = a[n-1] > x ? 0 : 1;

    for(int i=n-2;i>=0;i--){
        //solving for dp[i]
        //lli required_sum = m2[i] + x;
        lli required_sum = pre[i] + x;    
        int index = upper_bound(pre.begin(), pre.end(), required_sum) - pre.begin();
        // cout<<"for i="<<i<<" "<<"index="<<index<<"\n";
        if(index==n+1) dp[i] = n - i;
        else if(index==n) dp[i] = n - i -1;
        else{
            dp[i] = index -i-1 + dp[index];
        }

        // auto it = m1.upper_bound(required_sum);
        // auto it = 
        // if(it==m1.end()){
        //     dp[i] = n - i;
        // }else{
        //     lli index = it->second;
        //     index++;
        //     lli j = index-2;
        //     if(index==n) dp[i] = n - i -1 ;
        //     else dp[i] = dp[index] + index -1 - i;
        // }
    }
    lli ans = 0;
    for(int i=0;i<n;i++) ans += dp[i];

    // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    // cout<<"\n";
    cout<<ans<<"\n";
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