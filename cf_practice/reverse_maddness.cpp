// THE BASIC SNIPPET
// We have template for fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,k ;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>l(k), r(k);
    for(int i=0;i<k;i++) cin>>l[i];
    for(int i=0;i<k;i++) cin>>r[i];

    int q; cin>>q;
    vector<int>cnt(n+1,0);
    while(q--){
        int x;
        cin>>x;
        cnt[x]++;
    }
    // for(int it:cnt) cout<<it<<"\n";
    // cout<<"\n";

    for(int i=0;i<k;i++){
        int low = l[i];
        int high = r[i];
        int sum = 0;
        for(int j=low;j<=(low+high)/2;j++){
            sum += cnt[j] + cnt[high + low - j];
            if(sum&1) {
                swap(s[j-1], s[high-1 - j + low]);
                //  cout<<j-1<<" "<<high-1-j+low<<"\n";//
            }
        }
        
    }
     cout<<s<<"\n";
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