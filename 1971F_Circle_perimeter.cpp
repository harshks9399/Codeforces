// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int r;
    cin>>r;
    lli ans = 0;
    for(int x=1;x<=r;x++){
        int y = r;
        float k1,k2;
        int y1,y2;
        k1 = sqrt(r*r - x*x);
        k2 = sqrt(r*r + 1 + 2*r - x*x);
        y1 = ceil(k1);
        y2 = floor(k2);
        if(floor(k2)==ceil(k2)) y2--;
        ans += y2 - y1 + 1;
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