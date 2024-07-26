// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<char>a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        multiset<char>s1,s2;
        for(int i=l;i<=r;i++){
            s1.insert(a[i]);
            s2.insert(b[i]);
        }
        int ans = 0;
        for(auto c:s1){
            // cout<<c<<"\n";
            if(s2.find(c)!=s2.end()){
                // cout<<"c="<<c<<"\n";
                s2.erase(s2.find(c));
            }else ans++;
        }
        cout<<ans<<"\n";
    }
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