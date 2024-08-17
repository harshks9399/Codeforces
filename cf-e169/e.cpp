/*
 Author : Harsh Kumar Singh
 created at : 2024-08-15 20:57:11
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<lli>v(n);
    for(lli &it : v) cin>>it;

    sort(v.begin(), v.end());

    int cnt = 0;
    for(lli it: v) if(it==2) cnt ++;
    if(cnt % 2 == 1) cout<<"Bob\n";
    else cout<<"Alice\n";
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