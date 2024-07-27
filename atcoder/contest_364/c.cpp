// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void solve(){
    lli n,x,y;
    cin>>n>>x>>y;
    multiset<lli>sweet,salt;
    for(int i=0;i<n;i++) {lli a;cin>>a;sweet.insert(-a);}
    for(int i=0;i<n;i++) {lli a;cin>>a;salt.insert(-a);}

    lli ans = __LONG_LONG_MAX__/10;
    lli s1 = 0, s2=0, c1 = 0, c2 = 0;
    while(sweet.size()!=0){
        if(s1>x) {ans = c1;break;}
        s1 += -1 *  (*sweet.begin());
        c1++;
        sweet.erase(sweet.begin());
    }
    while(salt.size()!=0){
        if(s2>y) {ans = ans > c2 ? c2 : ans;break;}
        s2 += -1 * (*salt.begin());
        c2++;
        salt.erase(salt.begin());
    }
    if(ans==__LONG_LONG_MAX__/10) ans = n;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t=1;
    while(t--)
        solve();
    return 0;
}