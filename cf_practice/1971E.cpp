// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,k,d;
    cin>>n>>k>>d;
    vector<lli>dist(k+1), time(k+1);
    for(int i=1;i<=k;i++) cin>>dist[i];
    for(int i=1;i<=k;i++) cin>>time[i];

    while(d--){
        lli q;
        cin>>q;
        if(q==n){
            cout<<time[k]<<" ";
            continue;
        }

        int index = lower_bound(dist.begin(), dist.end(), q) - dist.begin();
        if(dist[index]==q) {
            cout<<time[index]<<" ";
            continue;
        }
        index--;
        lli ans = time[index];
        lli rem =  q - dist[index] ;
        ans += ((time[index+1] - time[index]) * rem) / (dist[index+1] - dist[index]);
        cout<<ans<<" ";
    }
    cout<<"\n";
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