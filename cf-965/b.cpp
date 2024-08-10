// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>og(n);
    for(int i=0;i<n;i++) cin>>og[i];
    
    vector<int>ans(n);
    ans[n-1] = og[0];
    for(int i=1;i<n;i++){
        ans[i-1] = og[i];
    }
    for(int it:ans) cout<<it<<" ";
    cout<<" ";
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