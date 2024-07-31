// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    lli n;cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2==1) n = 3*n + 1;
        else n = (n/2);
        cout<<n<<" ";
    } 
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}