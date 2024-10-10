/*
 Author : Harsh Kumar Singh
 created at : 2024-10-10 19:47:01
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

string build(string &s){
    string t = "";
    for(char c : s) { t += string("#") + c;}
    t += '#';
    return t;
}



int solve(){
    long n,x,h;
    cin>>n>>x>>h;
    string s;
    cin>>s;

    string t= build(s);
    vector<int>p(t.size(), 1);
    int l = 1, r = 1;

    for(int i=1;i<t.size();i++){
        if(l+r-i >=0 && l+r-i < t.size()) p[i] = max(1, min(r-i, p[l+r-i]));

        while(i - p[i] >= 0 && i + p[i] < t.size() && t[i - p[i]] == t[i + p[i]])
            p[i]++;

        if(i+p[i] > r ){
            r = i+p[i];
            l = i-p[i];
        }
    }

    int ans = *max_element(p.begin(), p.end());
    ans--;
    long temp = (ans * 1ll ) * h;
    if(temp >= x) return 1;
    else return 0;

}

int main()
{
    // string s = "checking";
    // cout<<build(s);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        cout<<solve()<<"\n";
    return 0;
}