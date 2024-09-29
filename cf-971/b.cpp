/*
 Author : Harsh Kumar Singh
 created at : 2024-09-03 20:07:56
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>ans;
    while(n--){
        for(int i=1;i<=4;i++){
            char c;
            cin>>c;
            if(c=='#') ans.push_back(i);
        }
    }
    n = ans.size();
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
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