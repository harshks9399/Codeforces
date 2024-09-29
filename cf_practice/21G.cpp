/*
 Author : Harsh Kumar Singh
 created at : 2024-08-21 15:27:07
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string)
#include <bits/stdc++.h>
using namespace std;
#define lli long long int


vector<int> pi_table(string s){
    int n = s.size();
    vector<int> ans(n,0);
    for(int i=1;i<n;i++){
        int j = ans[i-1];
        while(j > 0 && s[i] != s[j]  ) j = ans[j-1];
        if(s[i]==s[j]) j++;
        ans[i] = j;
    }
    return ans;
}


void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> a = pi_table(s);
    for(int i=0;i<n;i++) cout<<s[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
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