// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    lli n,s,m;
    cin>>n>>s>>m;
    vector<pair<lli,lli>>v;
    while(n--){
        lli x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    v.push_back({m,m});

    sort(v.begin(), v.end());
    lli curr = 0;
    for(auto it:v){
        lli start = it.first, end = it.second;
        lli rem = start - curr;
        if(rem >= s) {
            cout<<"YES\n";
            return;
        }
        curr = end;
    }
    cout<<"NO\n";
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