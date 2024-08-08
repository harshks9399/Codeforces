// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    map<lli,lli>m;
    for(string s: v){
        lli score = 0;
        for(char c:s) {
            lli temp = c;
            score = score ^ temp;
        }
        cout<<s<<" "<<score<<"\n";
        m[score] ++;
    }
    lli ans= 0;
    for(auto it: m){
        // cout<<it.first<<" "<<it.second<<"\n";
        lli cnt = it.second;
        ans += (cnt * (cnt-1))/2;
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