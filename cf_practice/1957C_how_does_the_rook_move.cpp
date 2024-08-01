// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int MOD = 1e9 + 7;
vector<lli>dp(3e5+2,-1);


lli solve_dp(int index){
    if(dp[index]==-1){
        dp[index] = solve_dp(index-1) + 2*(index - 1)*solve_dp(index-2);
        dp[index] %= MOD;
        return dp[index];
    }
    return dp[index];
}

void solve(){
    dp[0] = 1;
    dp[1] = 1;
    int n,k_;
    cin>>n>>k_;
    // vector<pair<int,int>>v;
    int count = n;
    for(int i=0;i<k_;i++){
        int x,y;
        cin>>x>>y;
        // v.push_back(make_pair(x,y));
        if(x==y)
            count--;
        else
            count = count-2;
    }
    cout<<solve_dp(count)<<"\n";
    return ;


    
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