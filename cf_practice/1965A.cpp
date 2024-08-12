
// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<lli>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    set<int>s;
    for(int it:v) s.insert(it);
    v.clear();
    for(int it:s) v.push_back(it);

    if(v.size()==1) {
        cout<<"Alice\n";
        return;
    }
    int flag = 1;
    int check = 1;
    for(int it: v){
        if(it==check){
            check++;
            if(it!=v[v.size()-1]) flag = (flag==0);
        }
        else break;
    }

    if(flag) cout<<"Alice\n";
    else cout<<"Bob\n"; 
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