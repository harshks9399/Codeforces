// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    lli ans = v[0];
    lli curr = 0;

    for(int it:v){
        curr += it;
        ans = ans > curr ? ans : curr;
        if(curr < 0 ) curr = 0;
    }
    cout<<ans;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}