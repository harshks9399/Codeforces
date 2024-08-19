/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 14:26:05
*/
//TEMPLATES : ft, expo, gcd, seive
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int gcd(int a,int b){
    if(a > b) return gcd(b,a);
    if(a==0) return b;
    return gcd(b%a, a); 
}

void solve(){
    int n;
    cin>>n;
    // vector<int>v(n);
    // for(int &it: v) cin>>it;

    // int ans = 1;
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++) ans = max(ans, gcd(v[i], v[j]));
    // }
    // cout<<ans<<"\n";
    // return ;
    const int N = 1e6 + 1;
    vector<int>div(N, 0);

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int i = 1; i*i<=a; i++){
            if(a%i!=0) continue;
            int x = i;
            int y = a/i;
            div[x]++;
            if(y!=x) div[y]++;
        }
    }

    for(int i=N;i>=1;i--){
        if(div[i]>=2){
            cout<<i<<"\n";
            return;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}