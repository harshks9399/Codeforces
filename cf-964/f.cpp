// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1e9+7;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    


    if(k==1){
        lli ans = 0;
        for(int it:v) ans += it;
        cout<<ans<<"\n";
        return;
    }
    lli ans = 0;
    int lb= (k/2);
    int ub = n-1 - (lb);
    for(int i=lb;i<=ub;i++){
        if(v[i]==0) continue; 
        lli left = i-1;
        lli right = n-1-i;
        left = ((left*(left-1))/2) % mod;
        right = ((right*(right-1))/2) % mod;
        ans += (left*right) % mod;
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