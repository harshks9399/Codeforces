// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    if(n%4==0){
        cout<<n/4<<"\n";
        return;
    }
    int ans = 0;
    ans++;
    n = n-2;
    ans += (n/4);
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