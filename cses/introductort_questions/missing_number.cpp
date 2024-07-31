// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<int>v(n+1);
    n--;
    while(n--){
        int x;cin>>x;
        v[x] = 1;
    }
    n = v.size()-1;
    for(int i=1;i<=n;i++) if(v[i]==0) cout<<i<<" ";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}