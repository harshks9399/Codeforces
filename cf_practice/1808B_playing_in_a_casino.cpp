// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>v(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            v[i][j] = x;
        }
    }
    if(n==1) {
        cout<<"0\n";
        return;
    }

    vector<vector<lli>>vt(m ,vector<lli>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vt[i][j] = v[j][i];
        }
    }
    for(int i=0;i<m;i++){
        sort(vt[i].begin(), vt[i].end());
    }


    // for(auto vec : vt){
    //     for(auto it:vec)
    //         cout<<it<<" ";
    //     cout<<"\n";
    // }


    lli ans = 0;
    for(int i=0;i<m;i++){
         //v[i] vector size is n
        lli sum = 0;
        for(int j =0 ;j<n;j++){
            if(j == 0) sum += -1 * (n-1) * vt[i][j];
            else sum += vt[i][j] * j  - (n-1-j)*vt[i][j];
        }        
        // cout<<"vector "<<i<<" \t sum = "<<sum<<"\n";
        ans += sum;
    }
    cout<<ans<<"\n";

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