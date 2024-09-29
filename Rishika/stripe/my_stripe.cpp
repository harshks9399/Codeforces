/*
 Author : Harsh Kumar Singh
 created at : 2024-09-24 20:05:23
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int





string solve(string s, string amt){
    string ans = amt;
    if(s=="EUR" || s=="USD" || s=="SGD" || s=="BRL"){
        int k = amt.size();
        while(k<3){
            ans = '0' + ans;
            k++;
        }
        ans.insert(ans.size()-2, ".");
    }
    else{
        ans += ".00";
        return ans;
    }
    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string amt;
    cin>>s>>amt;
    cout<<solve(s,amt)<<"\n";
    return 0;
}