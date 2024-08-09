// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli doit(vector<lli>&v){
    lli ans = 0;
    lli maxi  = 0 ;
    set<lli>check;
    for(lli i=0;i<v.size();i++){
        if(check.find(v[i])!= check.end()){
            if(maxi < v[i]) maxi = v[i];
        }else check.insert(v[i]);

        v[i] = maxi;
        ans += maxi;
    }
    return ans;
}



void solve(){
    lli n;
    cin>>n;
    lli tot = 0;
    vector<lli>v(n);
    for(lli i=0;i<n;i++){
        cin>>v[i];
        tot+=v[i];
    }
    if(n==1) {
        cout<<v[0]<<"\n";
        return;
    }

    lli ans = 0;
    ans += tot;
    
    ans += doit(v);
    ans += doit(v);
    
    for(lli i=0;i<n;i++){
        ans += (n-i-1)* 1LL * v[i];
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