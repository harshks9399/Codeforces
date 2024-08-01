// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,m;
    cin>>n>>m;

    

    vector<pair<int,int>>monsters, boundry;
    vector<vector<int>>v(n,vector<int>(m)), dist1(n,vector<int>(m,-1)), dist(n,vector<int>(m,-1));
    int ax,ay,bx,by;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            if(x=='A') {ax = i; ay = j; }
            if(x=='B') {bx = i; by = j; }
            if(x=='#') {v[i][j] = 1;}
            if(x=='M') { monsters.push_back({i,j});}


            if(x=='.' && (i==0 || i==n-1 || j==0 || j==m-1)) boundry.push_back({i,j});
        }
    }
    vector<int>row = {1,0,-1,0};
    vector<int>col = {0,1,0,-1};
    queue<pair<int,int>>q;
    



    q.push(make_pair(bx,by));
    while(q.size()!=0){
        auto top = q.front();
        q.pop();
        int x = top.first, y = top.second;
        cout<<"HERE\t"<<x<<" "<<y<<"\n";
        // if(dist[x][y]!=-1) continue;
        for(int i=0;i<4;i++){
            int r = x + row[i];
            int c = y + col[i];
            if(r<0 || c<0 || r>=n || c>=m) continue;
            if(v[r][c]==1 || dist[r][c]!=-1) continue;
            dist[r][c] = dist[x][y] + 1;
            q.push({r,c});
        }
    }

    if(dist[ax][ay]==-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;


}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
        solve();
    return 0;
}