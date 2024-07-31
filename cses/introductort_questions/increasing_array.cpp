// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    lli ans = 0;
    int prev = -1;
    while(n--){
        int x;
        cin>>x;
        if(x < prev){
            ans += prev-x;
            x = prev;
        }
        prev = x;
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}