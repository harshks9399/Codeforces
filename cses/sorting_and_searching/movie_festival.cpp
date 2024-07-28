// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v[i] = make_pair(b,a);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int curr = 0;
    for(auto it:v){
        int start = it.second, end = it.first;
        if(curr > start)continue;
        ans++;
        curr = end;
    }
    cout<<ans<<'\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}