// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int H,W;
    cin>>H>>W;
    int x,y;cin>>x>>y;
    vector<vector<int>>grid(H,vector<int>(W,0));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char a;cin>>a;
            if(a=='#')  grid[i][j] = 1;
        }
    }

    // cout<<"grid\n";
    // for(auto it1:grid){
    //     for(int it:it1) cout<<it<<" ";
    //     cout<<"\n";
    // }


    string s;cin>>s;
    for(char a:s){
        if(a=='U'){
            if(x==1) continue;
            if(grid[x-1-1][y-1]==1) continue;
            x--;
        }
        if(a=='D'){
            if(x==H) continue;
            if(grid[x+1-1][y-1]==1) continue;
            x++;
        }
        if(a=='L'){
            if(y==1) continue;
            if(grid[x-1][y-1-1]==1) continue;
            y--;
        }
        if(a=='R'){
            if(y==W) continue;
            if(grid[x-1][y+1-1]==1) continue;
            y++;
        }
    }
    cout<<x<<" "<<y;
    return;
    
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    // cin >> t;
    t=1;
    while(t--)
        solve();
    return 0;
}