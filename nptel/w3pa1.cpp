/*
 Author : Harsh Kumar Singh
 created at : 2024-08-15 00:30:42
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    // lli n,k;
    // cin>>n>>k;
    // multiset<lli>check;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     check.insert(x);
    //     if(check.size() > 2) check.erase(prev(check.end()));
    // }
    // lli tot =0 ;
    // for(auto it: check) tot += it;
    // if(tot > k) cout<<k<<"\n";
    // else cout<<k-tot<<"\n";
    // return;


    lli n,k,a,b,temp;
    cin>>n>>k>>a>>b;
    temp = a + b;
    a = a < b ? a : b;
    b = temp - a;

    for(int i=2;i<n;i++){
        lli x; cin>>x;
        // a < b
        if(x < a) {
            b = a;
            a = x;
        }else if(x < b){
            b = x;
        }
    }

    lli tot = a + b;
    if(tot > k) cout<<k<<"\n";
    else cout<<k-tot<<"\n";
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