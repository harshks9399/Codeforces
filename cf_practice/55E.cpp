/*
 Author : Harsh Kumar Singh
 created at : 2024-08-22 14:16:21
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

const int N = 3e3+1;
vector<vector<int>>adj(N, vector<int>());
multiset<tuple<int,int,int>>check;
int n,m,k;
void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        check.insert(make_tuple(a,b,c));
    }
    vector<vector<int>>dist(n+1, vector<int>(n+1, -1));
    vector<vector<int>>par(n+1, vector<int>(n+1, -1));
    dist[1][1] = 0;
    par[1][0] = 0;
    dist[1][0] = 0;
    queue<pair<int,int>>q;
    q.push(mp(1,0));
    while(1){
        if(q.size()==0) break;
        auto top = q.front();
        q.pop();
        int curr=top.first, prev= top.second;
        int curr_d = dist[curr][prev];

        if (curr == n) {
            // ndist = curr_d;
            // idx = prev;
            break; // Early exit when we reach the target node
        }
        

        for(int it: adj[curr]){  
            auto temp = make_tuple(prev, curr, it);
            if(check.find(temp) != check.end()) continue;
            int odist = dist[it][curr], ndist = curr_d + 1;
            if(odist > ndist || odist==-1){
                dist[it][curr] = ndist;
                q.push(mp(it, curr));
                par[it][curr] = prev;
            }
        }
    }
    int idx = -1;
    int ndist = INT_MAX;
    for(int i=1;i<n;i++) {
        if(dist[n][i]==-1) continue;
        if(dist[n][i] < ndist){
            ndist = dist[n][i];
            idx = i;
        }
    }
    if(idx==-1){
        cout<<"-1\n";
        return;
    }

    int d = 0;
    int t1 = n, t2 = idx;
    stack<int>st;
    st.push(n);
    while(t2!=0){
        int temp = par[t1][t2];
        t1 = t2;
        t2 = temp;
        st.push(t1);
        d++;
    }
    cout<<d<<"\n";
    while(st.size()!=0) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}