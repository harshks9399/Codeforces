/*
 Author : Harsh Kumar Singh
 created at : 2024-08-29 22:30:06
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 2e5 +1 ;
vector<int>par(N,-1);
vector<vector<int>>adj(N,vector<int>());
vector<int>vis(N,0);
vector<int>_rank(N, 0);

void make_set(int x){
    if(par[x]!=-1) return ;
    par[x] = x;
    return;
}

int find_par(int x){
    if(par[x]==x) return x;
    return par[x] = find_par(par[x]);
}

void join(int x, int y){
    x = find_par(x);
    y = find_par(y);
    if(x==y) return;
    if(_rank[x] < _rank[y]) swap(x,y);
    par[y] = x;
    if(_rank[x]==_rank[y]) _rank[x]++;
}


void dfs(int curr, int top , int & maxi){
    maxi = max(curr, maxi);
    vis[curr] = 1;
    for(int it: adj[curr]){
        if(vis[it]==1) continue;
        dfs(it, curr, maxi);
    }
}

void solve(){
    int n,q;
    cin>>n>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(a!=b) {
            adj[a].push_back(b);
            adj[b].push_back(a);    
        }
        make_set(a);
        make_set(b);
        join(a,b);
    }
    bool good = true;
    for(int i=1;i<=n;i++){
        if(par[i]!=-1) continue;
        good = false;
        break;
    }
    if(!good){
        cout<<"No";
        return;
    }

    int temp=1;
    while(1){
        int maxi = temp;
        dfs(temp, 0 , maxi);
        if(maxi==n-1){
            if(par[n]!=n) good = false;
            break;  
        }
        if(adj[maxi].size()==0){
            if(par[maxi]!=maxi) {
                good = false;
                break;
            }
            maxi++;
            temp = maxi;
            continue;
        }
        if(maxi==temp){
            good = false;
            break;
        }
        if(maxi==n) break;
        temp = maxi + 1;
    }if(!good){
        cout<<"No";
        return;
    }
    cout<<"Yes";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}