// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool fun(){
    string s;
    cin>>s;
    int n = s.size();
    if(n <= 2) return false;

    if(s[0]!='1' || s[1]!='0') return false;

    if(s[2]=='0') return false;
    if(n==3 && s[2]=='1') return false;
    return true;
}

void solve(){
    if(fun()) cout<<"YES\n";
    else cout<<"NO\n";
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