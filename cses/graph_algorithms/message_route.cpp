// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){

    int n,m;
    cin>>n>>m;
    map<int,vector<int>>edge;
    map<int,int>par;

    while(m--){
        int x,y;cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    queue<int>st;
    st.push(1);
    while(st.size()!=0){
        int top = st.front();
        st.pop();
        for(int it:edge[top]){
            if(par.find(it)!=par.end()) continue;
            par[it] = top;
            st.push(it);
        }
    }

    if(par.find(n)==par.end()){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    int out = n;
    vector<int>route;
    route.push_back(n);
    int ans = 0;
    while(out!=1){
        out = par[out];
        route.push_back(out);
        ans++;
    }
    cout<<route.size()<<"\n";
    for(int i=route.size()-1;i>=0;i--){
        cout<<route[i]<<" ";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}