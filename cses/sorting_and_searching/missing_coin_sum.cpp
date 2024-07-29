// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    sort(coins.begin(), coins.end());
   
    lli missing  = 1;


    for(int it:coins){
        if(it > missing) break;
        missing += it;
    }

    cout<<missing<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}