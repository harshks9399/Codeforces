// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli count(lli x){
    if(x == 0) return 0;
    return 1 + static_cast<int>(std::log(x) / std::log(3))
}

void solve(){
    int l,r;
    cin>>l>>r;
    multiset<lli>s;
    for(lli i=l;i<=r;i++) s.insert(i);

    lli ans = 0;
    int top = *s.begin();
    s.erase(s.begin());
    ans += 2*count(top);
    for(auto it: s) ans += count(it);
    cout<<ans<<"\n";
    //cout<< static_cast<int>(std::log(2e5) / std::log(3)) <<"\n";
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