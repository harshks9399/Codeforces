// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<lli>v(n);
    for(lli &it: v) cin>>it;
    vector<char>s(n);
    for(char &it: s) cin>>it;


    int l = 0;
    int r = n-1;
    // while(s[l]=='R'){
    //     l++;
    //     if(l==n-1) {
    //         cout<<"0\n";
    //         return;
    //     }
    // }

    // while(s[r]=='L'){
    //     r--;
    //     if(r<=0) {
    //         cout<<"0\n";
    //         return;
    //     }
    // }
    vector<lli>presum(n+1);
    for(int i=0;i<n;i++){
        presum[i+1] = v[i] + presum[i];
    }

    lli ans = 0;
    // l = 0;
    // r = n-1;
    while(l<r){
        if(s[l]=='R') {
            l++;
            continue;
        }
        if(s[r]=='L'){
            r--;
            continue;
        }
        ans += presum[r+1] - presum[l];
        r--;
        l++;
    }
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