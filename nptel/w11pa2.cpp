/*
 Author : Harsh Kumar Singh
 created at : 2024-10-10 20:13:38
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int solve(){
    int n,m;
    cin>>n>>m;
    vector<int>ans(n,1);
    for(int i=1;i<m;i++){
        vector<int>temp(n);
        temp[0] = 1;
        for(int j=1;j<n;j++) temp[j] = temp[j-1] + ans[j];
        ans = temp;
    }
    return ans[n-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        cout<<solve()<<"\n";
    return 0;
}