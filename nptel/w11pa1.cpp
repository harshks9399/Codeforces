/*
 Author : Harsh Kumar Singh
 created at : 2024-10-10 13:26:27
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int helper(string text) 
{ 
    int N = text.length(); 
    if (N == 0) 
        return; 
  
    // Position count 
    N = 2 * N + 1; 
  
    // LPS Length Array 
    int L[N]; 
    L[0] = 0; 
    L[1] = 1; 
  
    // centerPosition 
    int C = 1; 
  
    // centerRightPosition 
    int R = 2; 
  
    // currentRightPosition 
    int i = 0; 
  
    // currentLeftPosition 
    int iMirror; 
    int expand = -1; 
    int diff = -1; 
    int maxLPSLength = 0; 
    int maxLPSCenterPosition = 0; 
    int start = -1; 
    int end = -1; 
\ 
    for (i = 2; i < N; i++) { 
        // Get currentLeftPosition iMirror 
        // for currentRightPosition i 
        iMirror = 2 * C - i; 
\
        expand = 0; 
        diff = R - i; 
  
\
        if (diff >= 0) { 
  
            // Case 1 
            if (L[iMirror] < diff) 
                L[i] = L[iMirror]; 
  
            // Case 2 
            else if (L[iMirror] == diff && R == N - 1) 
                L[i] = L[iMirror]; 
  
            // Case 3 
            else if (L[iMirror] == diff && R < N - 1) { 
                L[i] = L[iMirror]; 
  
                // Expansion required 
                expand = 1; 
            } 
  
            // Case 4 
            else if (L[iMirror] > diff) { 
                L[i] = diff; 
  
                expand = 1; 
            } 
        } 
        else { 
            L[i] = 0; 
              expand = 1; 
        } 
  
        if (expand == 1) { 
           while (((i + L[i]) < N && (i - L[i]) > 0) 
                   && (((i + L[i] + 1) % 2 == 0) 
                       || (text[(i + L[i] + 1) / 2] 
                           == text[(i - L[i] - 1) / 2]))) { 
                L[i]++; 
            } 
        } 
        if (L[i] > maxLPSLength) { 
            maxLPSLength = L[i]; 
            maxLPSCenterPosition = i; 
        } 
  

        if (i + L[i] > R) { 
            C = i; 
            R = i + L[i]; 
        } 
    } 
  
    start = (maxLPSCenterPosition - maxLPSLength) / 2; 
    end = start + maxLPSLength - 1; 
  

    return end-start+1;
} 


void solve(){
    int n;
    ll s,x;
    cin>>n>>x>>s;
    string chant;
    cin>>chant;
    // int maxi = 1;
    // vector<vector<int>>dp(n,vector<int>(n));
    // for(int i=0;i<n;i++) dp[i][i] = 1;
    // for(int i=0;i<n-1;i++) {
    //     if(chant[i]==chant[i+1]) {
    //         dp[i][i+1] = 1;
    //         maxi = 2;
    //         }
    //     }

    // for(int k=3;k<=n;k++){
    //     for(int i=0;i<=n-k;i++){
    //         int j = i+k-1;
    //         if(dp[i+1][j-1]==1 && chant[i]==chant[j]){
    //             dp[i][j] = 1;
    //             maxi = k;
    //         }
    //     }
    // }
    int maxi =  helper(chant);
    s = s * (maxi * 1ll);
    if(s >= x) cout<<1<<"\n";
    else cout<<0<<"\n";
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