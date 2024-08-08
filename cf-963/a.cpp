// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>m;
    for(char c: s) m[c]++;
    int ans = 0;
    for(auto it:m){
        if(it.first == '?') continue;

        ans += min(it.second, n);
    }
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