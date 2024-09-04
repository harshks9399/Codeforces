/*
 Author : Harsh Kumar Singh
 created at : 2024-09-04 10:55:48
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>en;
    lli temp = n;
    while(temp!=0){
        en.push_back(temp%4);
        temp = temp / 4;
    }
    reverse(en.begin(), en.end());
    
    bool good = true;
    for(int i=0;i<en.size();i++){
        if(en[i]!=0 && en[i]!=1) good = false;
        if(!good) en[i]=1;
    }
    // for(int it: en )cout<<it;
    lli ans = 0;
    temp = 1;
    for(int i=en.size()-1;i>=0;i--){
        if(en[i]==1) ans += temp;
        temp = temp << 1;
    }
    if(good && ans!=0) ans--;
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}