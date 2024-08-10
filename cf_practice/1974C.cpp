// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<lli> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    map<vector<lli>, lli> m;
    lli ans =0;     
    for(int j=2;j<n;j++){
        vector<lli> og = {v[j-2], v[j-1], v[j]};
        vector<vector<lli>>a(3, og);
        a[0][0] = 0;
        a[1][1] = 0;
        a[2][2] = 0;


        for(auto vec : a){
            ans += m[vec] - m[og];
            m[vec]++;
        }
        m[og]++;
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