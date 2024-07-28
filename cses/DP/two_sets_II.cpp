// // THE BASIC SNIPPET
// #include <bits/stdc++.h>
// using namespace std;
// #define lli long long int
// const int mod = 1e9 + 7;


// void solve(){
//     int n;cin>>n;
//     int sum = (n*(n+1))/2;
//     if(sum%2==1){
//         cout<<0<<"\n";
//         return;
//     }
//     int hsum = sum/2;

//     unordered_map<int,lli> start;
//     start[0] = 0;
//     start[1] = 1;

//     for(int i=2;i<=n;i++){
//         unordered_map<int,lli> curr;
//         curr = start;
//         curr[i]++;
//         for(auto it:start){
//             curr[it.first + i] += it.second;
//             curr[it.first + i] %= mod;
//         }
//         start = curr;
//     }
//     // for(auto it:start){
//     //     cout<<it.first<<" "<<it.second<<"\n";
//     // }
//     cout<< (start[hsum])/2;
//     return;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//         solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  int target = n*(n+1)/2;
  if (target%2) {
    cout << 0 << endl;
    return 0;
  }
  target /= 2;

  vector<vector<int>> dp(n,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-i;
      if (left >= 0) {
	(dp[i][j] += dp[i-1][left]) %= mod;
      }
    }
  }
  cout << dp[n-1][target] << endl;
}