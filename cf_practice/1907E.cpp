// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int


lli one(int n){
    if(n==0) return 1;
    if(n==1) return 3;
    lli ans = (((n+1)*(n))/2) + n+1;
    return ans;
}

void solve(){
    int n;
    cin>>n;
    // if(n==0) return 1;
    lli ans = 1;
    while(n!=0){
        int dig = n%10;
        n = n/10;
        ans *= one(dig);
    }
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