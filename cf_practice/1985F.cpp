// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool fun_sort(pair<lli,lli> p1, pair<lli,lli> p2){
    if(p1.first != p2.first) return p1.first < p2.first;
    return p1.second > p2.second;
}

void solve(){
    int h,n;
    cin>>h>>n;
    vector<lli>a(n), c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>c[i];
   
    set<pair<lli,lli>> check;
    lli last = 0;

    for(int i=0;i<n;i++) check.insert({1,i});

    while(1){
        //auto [t, idx]  = *check.begin();
        auto tt = *check.begin();
        lli t = tt.first, idx = tt.second;
        check.erase(check.begin());
        h -= a[idx];
        last=  t;
        if(h<=0) break;
        check.insert({t+c[idx], idx}); 
    }
    cout<<last<<"\n";    
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