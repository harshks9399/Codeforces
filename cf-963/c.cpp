// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,k;cin>>n>>k;
    vector<lli>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    sort(v.begin(), v.end());
    if(n==1){
        cout<<1<<"\n";
        return;
    } 
    lli maxi = v[n-1];
    for(int i=0;i<n-1;i++){
        lli diff = maxi - v[i];
        lli mul = (diff/(2*k));
        // if(diff%(2*k)!=0) mul++; 
        v[i] += mul*2*k;
        if(diff%(2*k)==0) continue;
        lli maxi_last = maxi + k - 1;
        lli one_last = v[i] + 2*k;
        if(one_last <= maxi_last) v[i] += 2*k;
    }
    sort(v.begin(),v.end());
    
    // cout<<"check\n";
    // for(auto it:v) cout<<it<<" ";
    // cout<<"\n";

    multiset<lli>check;
    for(auto it: v) check.insert(it);

    for(auto it: v){
        if(check.find(it+k)!=check.end()){
            cout<<"-1\n";
            return;
        }
    }
    lli one_last = v[0] + k -1;
    if(one_last >= v[n-1])
        cout<<v[n-1]<<"\n";
    else cout<<"-1\n";
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