// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    // cout<<n<<k<<"\n";
    int m = n/k;
    // cout<<n<<m<<k<<"\n";
    vector<vector<char>>v(n, vector<char>(n,0));
    vector<vector<char>>ans(m, vector<char>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            v[i][j] = x;
            // cout<<"X="<<x<<"\n";
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            ans[i][j] = v[i*k][j*k];
        }
    }
    for(auto vv:ans){
        for(char it:vv)
            cout<<it;
        cout<<"\n";
    }
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