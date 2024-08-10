// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int x,y,k;
    cin>>x>>y>>k;

    vector<int>h,v;
    if(k%2==1) {
        h.push_back(x);
        v.push_back(y);
        k--;
    }
    k = k/2;
    int i = 1;
    while(k--){
        int r1 = x-i, r2 = x+i;
        int c1 = y-i, c2 = y+i;
        i++;
        h.push_back(r1);
        h.push_back(r2);
        v.push_back(c1);
        v.push_back(c2);
    }

    for(int i=0;i<h.size();i++){
        cout<<h[i]<<" "<<v[i]<<"\n";
    }
    cout<<"\n";
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