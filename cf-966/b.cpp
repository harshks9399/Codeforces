// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &it: a) cin>>it;

    multiset<int>check;
    check.insert(a[0]);

    for(int i=1;i<n;i++){
        if(check.find(a[i]-1)== check.end() && check.find(a[i]+1)==check.end()){
            cout<<"NO\n";
            return;
        }
        check.insert(a[i]);
    }
    cout<<"YES\n";
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