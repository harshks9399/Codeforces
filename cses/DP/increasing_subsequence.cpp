// // THE BASIC SNIPPET
// #include <bits/stdc++.h>
// using namespace std;
// #define lli long long int


///////// O(N^2) solution



// void solve(){
//     int n;cin>>n;
//     vector<int>a(n);
//     for(int i=0;i<n;i++) cin>>a[i];

//     vector<int>dp(n,1);
//     dp[0] = 1;
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (a[j] < a[i]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }

//     cout<<*max_element(dp.begin(), dp.end());
//     return;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//         solve();
//     return 0;
// }


// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>lis;

    for(int it: v){
        if(lis.empty() || lis.back() < it) lis.push_back(it);
        else{
            auto loc = lower_bound(lis.begin(), lis.end(), it);
            *loc = it;
        }
    }
    cout<<lis.size();
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}


