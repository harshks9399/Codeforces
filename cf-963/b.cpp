// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<lli>even, odd;
    lli ce= 0, co=0;
    for(int i=0;i<n;i++){
        lli x;
        cin>>x;
        if(x&1==1) odd.push_back(x);
        else even.push_back(x);
    }
    ce = even.size();
    co = odd.size();
    if(ce*co == 0){
        cout<<"0\n";
        return;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    lli me = *even.rbegin(), mo = *odd.rbegin();
    if(mo > me){
        cout<<ce<<"\n";
        return;
    }
    lli ans = 0;
    // cout<<"mo "<<mo<<"\n";
    for(lli it:even){
        // cout<<it<<" "<<mo<<"\n";
        if(it < mo){
            mo = (mo+it);
            ans++;
        }else{
            mo = (mo + 2*it);
            ans += 2;
        }

        
    }
    ans = ans > (ce +1) ? ce+1 : ans;
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