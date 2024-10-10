/*
 Author : Harsh Kumar Singh
 created at : 2024-10-03 18:03:21
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int



lli solver(vector<lli>&a){
    int n = a.size();
    //if(n<=2) return *max_element(a.beign(), a.end());
    vector<lli>dp = a;
    if(n>2) dp[2] += dp[0];
    for(int i=3;i<n;i++){
        dp[i] = a[i] + max(dp[i-2], dp[i-3]);
    }
    return *max_element(dp.begin(), dp.end());
}



lli solve(){
    int n;
    cin>>n;
    vector<lli>a(n);
    for(lli &it : a) cin>>it;
    if(n<=3) return *max_element(a.begin(), a.end());
    vector<lli>t1, t2;
    for(int i=0;i<n;i++){
        if(i!=0) t2.push_back(a[i]);
        if(i!=n-1) t1.push_back(a[i]);
    }
    return max(solver(t1), solver(t2));
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        cout<<solve()<<"\n";
    return 0;
}