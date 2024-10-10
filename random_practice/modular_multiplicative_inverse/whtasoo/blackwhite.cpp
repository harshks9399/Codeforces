#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
ll dp[10001][20001];  // i = node, j = black - white+1000 , val = path length
ll nodes[10001];
vector<vector<ll> > adj[1000+1];
void dij() // 3rd is black - white
{
    priority_queue<vector<ll>,vector<vector<ll> >,greater<vector<ll> > > pq;
    vector<ll> v(3);
    v[0]=0;
    v[1]=1;
    if(nodes[1]==0)
    v[2]=1001;
    else
    v[2]=999;
    pq.push(v);
    dp[1][v[2]] = 0;
    while(!pq.empty())
    {
        vector<ll> v = pq.top();
        ll dist = v[0];
        ll node = v[1];
        ll j = v[2];
        pq.pop();
        
        for(auto it: adj[node])
        {
            ll x = it[0];
            ll w = it[1];
            ll col = nodes[x];
            if(col==0)
            {
                if(dp[x][j+1]> dist+w)
                {
                    dp[x][j+1]=dist+w;
                    vector<ll> v(3);
                    v[0]=dist+w;
                    v[1] = x;
                    v[2] = j+1;
                    pq.push(v);
                }
            }
            else
            {
                if(dp[x][j-1]> dist+w)
                {
                    dp[x][j-1]=dist+w;
                    vector<ll> v(3);
                    v[0]=dist+w;
                    v[1] = x;
                    v[2] = j-1;
                    pq.push(v);
                }
            }
        }
    }


}
void solve()
{
    ll n, m , i , j , k,x,y,z;
    cin>>n>>m;
    
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        vector<ll> v(2);
        v[0]=y;
        v[1]=z;
        adj[x].push_back(v);
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        nodes[i+1]=x;
    }
    // memset(dp,1e8,sizeof(dp));
    for(i=0;i<10001;i++)
    {
        for(j=0;j<20001;j++)
        {
            dp[i][j] = 1e8;
        }
    }
    // cout<<endl;
    dij();
    ll ans = min(dp[n][1000], dp[n][1001]);
    if(ans==1e8)
    ans=-1;
    cout<<ans<<endl;
    return;
}
int main()
{
    solve();
    return 0;
}