// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    lli r;
    cin>>r;
    lli ans = 0;
    for(lli x=1;x<=r;x++){
        // lli a = x*x;
        // lli n1 = r*r;
        // lli n2 = (r+1)*(r+1);

        // lli lb = ceil(sqrt(n1 - a));
        // lli ub = sqrt(n2 - a);

        // if( ub*ub + a == n2  ) ub--;

        // ans += ub - lb + 1;
        double a = x*x;
        double n1 = r*r;
        double n2 = (r+1)*(r+1);
 
        int lb = ceil(sqrt(n1 - a));
        int ub = sqrt(n2 - a  - 0.1);
 
        ans += ub - lb + 1;
    
    }
    cout<< 4*ans <<"\n";

    
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