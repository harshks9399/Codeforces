// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    //int N=0,S=0,E=0,W=0;
    map<char,int>m;
    cin>>n;
    string s;cin>>s;
    for(char c: s){
        m[c]++;
    }
    int x=0,y=0;
    for(auto it:m){
        if(it.first=='N') x += it.second;
        if(it.first=='S') x -= it.second;
        if(it.first=='E') y += it.second;
        if(it.first=='W') y -= it.second;
    }

    if(abs(x)%2==1 || abs(y)%2==1 || (x==0 && y== 0 && n==2)){
        cout<<"NO\n";
        return;
    }
    // multiset<char>check;
    // check.insert('N');
    // check.insert('E');
    // check.insert('W');
    // check.insert('S');
    string ans = "";
    map<char, int>check;
    if(m['N']!=0) {
        check['N'] = 1;
        check['S'] = 1;
    }else{
        check['W'] = 1;
        check['E'] = 1;
    }
    for(char c: s){
        if(check[c]==0) ans+= 'R';
        else ans += 'H';
        check[c] = (check[c] == 0);
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