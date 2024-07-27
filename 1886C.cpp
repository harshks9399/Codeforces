// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    string s;
    long long int pos;
    cin>>s>>pos;
    long long int count = s.size();
    count--;
    string ans = "";
    ans = s;
    // cout<<"START\n";
    lli noop = 0;
    lli s_size = s.size();
    lli minus = 0;
    while(s_size < pos){ // optimize
        pos -= s.size()-minus;
        minus++;
        s_size = s.size()-minus;
        noop++;
    }
    int flag = 0;
    for(lli i=0;i<s.size()-1;i++){
        if(noop==0) break;
        if(s[i] > s[i+1]) {
            s.erase(s.begin()+i); 
            noop--;
            i = i-2;
            if(i==-2) i++;
        }
    }
    if(noop!=0) s.erase(s.end()-noop, s.end());
    cout<<s[pos-1];
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