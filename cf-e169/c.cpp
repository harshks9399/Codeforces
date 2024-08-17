/*
 Author : Harsh Kumar Singh
 created at : 2024-08-15 20:23:20
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,k;
    cin>>n>>k;
    vector<lli>v(n);
    for(lli &it: v) cin>>it;

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int i=0;i<n;i++){
        if(i%2==0) continue;
        if(k==0) break;
        lli diff = v[i-1] - v[i];
        if(k >= diff){
            k-= diff;
            v[i] += diff;
        }else{
            v[i] += k;
            k =0 ;
        }
    }
    lli ans = 0;
    for(int i=0;i<n;i++){
        if(i%2==0 )ans += v[i];
        else ans -= v[i];
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