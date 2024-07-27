// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int ans = 0, flag=0;
    // n--;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        if(s=="sweet") flag++;
        else flag = 0;
        if(ans==1) continue;

        if(flag>=2 && i!=n-1) ans=1;
    }

    if(ans) cout<<"No";
    else cout<<"Yes";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t=1;
    while(t--)
        solve();
    return 0;
}