/*
 Author : Harsh Kumar Singh
 created at : 2024-08-25 20:26:56
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<char>v;
    string s; cin>>s;
    for(char c:  s) v.push_back(c);
    map<char, int>m;
    bool many = false;
    for(char c: s){
        m[c]++;
        if(m[c] > 1) many = true;
    }

    if(!many){
        cout<<s<<"\n";
        return;
    }
    char maxc = '*';
    int count = 0 ;
    for(auto c : m){
        if(c.second > count) {
            count  = c.second;
            maxc = c.first;
        }
    }

    vector<vector<char>>ans(count, vector<char>(1, maxc));
    // for(auto vec : ans) vec.push_back(maxc);

    int idx = 0;
    for(auto c : m){
        char cc = c.first;
        int ccount = c.second;
        if(cc==maxc) continue;
        while(ccount--){
            ans[idx].push_back(cc);
            idx++;
            idx %= count;
        }
    }

    for(auto vec : ans) for(char c: vec) cout<<c;
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