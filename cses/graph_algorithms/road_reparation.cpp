/*
 Author : Harsh Kumar Singh
 created at : 2024-08-25 19:46:32
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
const int N = 1e5+1;
vector<int>par(N,-1);
vector<int>size(N,-1);

void make_set(int x){
    par[x] = x;
    size[x] = 0;
}

int find(int x){
    if(par[x]==x || par[x]==-1) return par[x] = x;
    return par[x] = find(par[x]);
}

void join(int x, int y){
    x =find(x);
    y =find(y);

    if(x==y) return;
    if(size[x] < size[y]){
        swap(y,x);
    }

    par[y] = x;
    if(size[x]==size[y]) size[x]++;
}



void solve(){
    int n,m;
    cin>>n>>m;
    priority_queue<
        pair<lli, pair<int,int>>,
        vector<pair<lli, pair<int,int>>>,
        greater<pair<lli, pair<int,int>>>
    > pq;
    for(int i=1;i<=n;i++) {
        // int x; cin>>x;
        make_set(i);
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push(mp(c, mp(a,b)));
    }
    lli cost = 0;
    while(pq.size()!=0){
        auto top = pq.top();
        pq.pop();
        int a = top.second.first, b = top.second.second;
        lli len = top.first;
        if(find(a)== find(b)) continue;
        cost += len;
        join(a,b);
    }

    bool good = true;
    int idx = find(1);
    for(int i=1;i<=n;i++){
        if(find(i)!=idx){
            good = false;
            break;
        }
    }
    if(good)
    cout<<cost<<"\n";
    else
    cout<<"IMPOSSIBLE\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}