// Author : Harsh Kumar Singh
//created at : 2024-08-14 09:05:55
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<char>v(n);
    for(char &it: v) cin>>it;
    for(int i=1;i<=n;i++){
        if(i==n){
            cout<<i<<"\n";
            return;
        }
        if(n%i!=0) continue;
        int good = 2;
        for(int j=0;j<n;j += i){
            for(int k=0;k<i;k++){
                if(v[j+k] != v[k]) good--;
            }
        }
        if(good >0 ){
            cout<<i<<"\n";
            return;
        }
        good = 2;
        for(int j=0;j<n;j += i){
            for(int k=0;k<i;k++){
                if(v[j+k] != v[n-i + k]) good--;
            }
        }
        if(good >0 ){
            cout<<i<<"\n";
            return;
        }
    }
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