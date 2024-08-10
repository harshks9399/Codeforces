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
    
    int n1 = n/2 + (n%2);
    int n2 = n/2;
    vector<int>a1(n1), a2(n2);
    for(int i=0;i<n;i++){

        if(i < n2) a2[i] = og[i];
        else a1[i-n2] = og[i];
    } 


    // int mid = n1;
    // for(int i=mid;i<n;i++){
    //     a2[i - mid] = og[i];
    // }
    // for(int i=0;i<mid;i++) a1[i] = og[i];
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());

    if(n%2==1){
        int l1 = a1[0], l2 = a1[n1-1];
        a1[n1-1] = l1;
        a1[0] = l2;
    }

    for(int it:a1) cout<<it<<" ";
    for(int it:a2) cout<<it<<" ";

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