// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,m;
    cin>>n;
    vector<int>v(n);
    for(int &it: v) cin>>it;
    cin>>m;
    vector<string>b(m);
    for(string &it: b) cin>>it;

    for(auto s:b){
        map<char,int>check1;
        map<int,char>check2;
        if(s.size()!=n){
            cout<<"NO\n";
            continue;
        }
        bool good = true;
        int idx = -1;
        for(char c:s){
            idx++;
            bool b1 = (check1.find(c)==check1.end() && check2.find(v[idx])!= check2.end());
            bool b2 = (check1.find(c)!=check1.end() && check2.find(v[idx])== check2.end());
            bool b3 = (check1.find(c)!=check1.end() && check2.find(v[idx])!= check2.end() && check1[c]!=v[idx]);
            bool b4 = (check1.find(c)!=check1.end() && check2.find(v[idx])!= check2.end() && check2[v[idx]]!=c);
            if(b1 || b2 || b3 || b4){
                good = false;
                break;
            }
            check1[c] = v[idx];
            check2[v[idx]] = c;
        }
        if(good) cout<<"YES\n";
        else cout<<"NO\n";
    }
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