// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    int m;cin>>m;

    map<int,vector<int>>edge;
    while(m--){
        int x,y;cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    map<int,int>team;
    // team[1] = 1;

    for(int i=1;i<=n;i++){
        if(team.find(i) != team.end()) continue;
        team[i] = 1;
        queue<int>q;
        q.push(i);
        while(q.size()!=0){
            int top = q.front();
            q.pop();
            for(int it:edge[top]){
                if(team.find(it)!=team.end()){
                    if(team[it]==team[top]){
                        cout<<"IMPOSSIBLE\n";
                        return;
                    }else continue;
                }

                team[it] = (team[top] % 2) + 1;
                q.push(it);
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<team[i]<<" ";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}