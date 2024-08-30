/*
 Author : Harsh Kumar Singh
 created at : 2024-08-30 12:34:31
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

const int N = 501;
vector<vector<lli>>C(N, vector<lli>(N,0));
vector<vector<int>>adj(N,vector<int>());
vector<vector<lli>>flow(N,vector<lli>(N,0));
vector<int>par(N,-1);
int n,m;
lli min_flow(){
    int s = 1;
    queue<pair<int,lli>>q;
    q.push(mp(s,LLONG_MAX/10));
    fill(par.begin(), par.end(), -1);
    while(q.size()!=0){
        auto top = q.front();
        q.pop();
        int curr = top.first;
        lli curr_min = top.second;
        for(int next: adj[curr]){
            if(par[next]!=-1) continue;
            lli curr_flow = C[curr][next] - flow[curr][next];
            if(curr_flow==0) continue;
            par[next] = curr;

            // cout<<"PATH = "<<curr <<" "<<next<<"\n";

            lli new_min = curr_flow > curr_min ? curr_min : curr_flow;
            if(next==n) return new_min;
            q.push(mp(next, new_min));
        }
    }
    return 0;
}


void solve(){
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        C[a][b] += c;
        // C[b][a] = 0;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // cout<<"graph made\n";

    lli max_flow = 0;
    lli new_flow ;
    while(new_flow = min_flow()){
        // cout<<"NEW_FLOW = "<<new_flow<<"\n";
        max_flow += new_flow;
        lli temp = n;
        while(temp!=1){
            lli prev = par[temp];
            flow[prev][temp] += new_flow;
            flow[temp][prev] -= new_flow;
            temp = prev;
        }
    }
    cout<<max_flow<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}