// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int>v(n);
    int index = 0;
    for(char c: s){
        string a  = "";
        a += c;
        v[index]  = stoi(a);
        index++;
    }
    if(v[0]!=1 && v[0]!=9) v[0] = min(v[0], 9 - v[0]);
    for(int i=1;i<n;i++){
        v[i] = min(v[i], 9 - v[i]);
    } 
    for(int it:v)
    cout<<it;
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t = 1;
    
    while(t--)
        solve();
    return 0;
}