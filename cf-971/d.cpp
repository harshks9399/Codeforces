/*
 Author : Harsh Kumar Singh
 created at : 2024-09-03 20:18:54
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    lli ans =0 ;
    // map<int,int>m0, m1, eq;
    vector<int>m0(n+1), m1(n+1), eq(n+1);
    lli one=0, zero=0, equal = 0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(y==0){
            m0[x]=1;
            zero++;
            if(m1[x]==1 && eq[x]!=1){
                eq[x]=1;
                equal++;
            }
        }else{
            m1[x]=0;
            one++;
            if(m0[x]==1 && eq[x]!=1){
                eq[x]=1;
                equal++;
            }
        }
    }

    // if(equal!=0) ans += (equal)
    ans += (equal) * (n-2);
    for(int i)


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