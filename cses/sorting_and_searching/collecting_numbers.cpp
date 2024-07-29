// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    // int count= 0;
    // int head = 1;
    // while(head!=n+1){
    //     for(int it:v) if(it==head) head++;
    //     count++;
    // }
    // cout<<count<<"\n";

    multiset<int>check;
    int ans = 0;
    for(int it:v){
        if(it==1){
            ans++;
            check.insert(it);
            continue;
        }
        check.insert(it);
        if(check.find(it-1)!=check.end()) continue;
        ans++;
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}