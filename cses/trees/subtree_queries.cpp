/*
 Author : Harsh Kumar Singh
 created at : 2024-08-17 18:19:41
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int n,q;
int N = 2e5 + 1;
int l = log2(N) + 1;
vector<lli>bit(N);
vector<vector<int>>adj(N, vector<int>());
vector<lli>tin(N), tout(N), val(N);
lli T = 0;

void update(int idx, lli value){
    for(int i=idx; i<=n; i += (i & (-i))){
        bit[i] += value;
    }
}

lli query(int idx){
    lli ans = 0;
    for(int i=idx; i>0 ; i -= i & -i) ans += bit[i];
    return ans;
}

void dfs(int idx, int par){
    T++;
    tin[idx] = T;
    update(T, val[idx]);
    for(int it:adj[idx]){
        if(it==par) continue;
        dfs(it, idx);
    }
    tout[idx] = T;
}

void solve(){
    
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        val[i] = a;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    // cout<<"TREE\n";
    // for(int i=1;i<=n;i++) cout<<tin[i]<<" ";
    // cout<<"\n";
    // for(int i=1;i<=n;i++) cout<<tout[i]<<" ";
    // cout<<"\n";
    // for(int i=1;i<=n;i++) cout<<bit[i]<<" ";

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int node, nval;
            cin>>node>>nval;
            update(tin[node], -val[node]);
            val[node] = nval;
            update(tin[node], val[node]);

        }else{
            int node;
            cin>>node;
            cout<< (query(tout[node]) - query(tin[node]-1))<<"\n";
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}