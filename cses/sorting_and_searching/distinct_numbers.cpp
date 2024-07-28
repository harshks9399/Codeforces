// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    multiset<int>s;
    while(n--){
        int x;cin>>x;
        if(s.find(x)==s.end()) s.insert(x);
    }
    cout<<s.size();
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}