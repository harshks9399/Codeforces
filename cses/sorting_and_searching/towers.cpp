// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    multiset<int>check;
    check.insert(v[0]);

    for(int i=1;i<n;i++){
        int num = v[i];

        // auto it = upper_bound(check.begin(), check.end(), num);      // -> THIS GIVES TLE
        auto it = check.upper_bound(num);
        if(it==check.end()) check.insert(num);
        else{
            check.erase(it);
            check.insert(num);
        }
    }
    cout<<check.size()<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}