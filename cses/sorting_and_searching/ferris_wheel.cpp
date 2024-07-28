// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>w(n);
    for(int i=0;i<n;i++) cin>>w[i];
    sort(w.begin(), w.end());
    int i=0,j=n-1;
    int ans =0 ;
    while(i<=j){
        if(i==j){
            ans++;
            break;
        }
        int sum = w[i] + w[j];
        if(sum <= x){
            ans++;
            i++;
            j--;
        }else{
            ans++;
            j--;
        }
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