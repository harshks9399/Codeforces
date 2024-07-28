// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int>app(n), rooms(m);
    for(int i=0;i<n;i++) cin>>app[i];
    for(int i=0;i<m;i++) cin>>rooms[i];
    sort(rooms.begin(), rooms.end());
    sort(app.begin(), app.end());

    int i=0,j=0;
    int ans = 0;
    while(1){
        if(i==n || j==m) break;
        int res = app[i] - rooms[j];

        if(abs(res) <=k ){
            i++;
            j++;
            ans++;
            continue;
        }
        if(res < 0 ){
            i++;
        }else j++;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}