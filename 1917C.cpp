// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,d;
    cin>>n>>k>>d;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int>v(k);
    for(int i=0;i<k;i++) cin>>v[i];

    int ans = 0;
    for(int i=0;i<d && i<=2*n;i++){
        int curr = 0;
        for(int j=0;j<n;j++) curr += (a[j]==j+1);
        curr += (d-i-1)/2;
        ans = ans > curr ? ans:curr;
        for(int j=0;j<v[i%k];j++){
            a[j]++;
        }
    }
    cout<<ans<<"\n";
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