/*
 Author : Harsh Kumar Singh
 created at : 2024-08-25 00:13:56
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin >> n;
    vector<vector<int>>dist(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++ ) cin>>dist[i][j];
    

    lli og = 0;
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) og += dist[i][j];

    // cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<dist[i][j]<<" ";
    //     cout<<"\n";
    // }

    int k;
    cin>>k;
    while(k--){
        int a,b,c;
        // lli curr = og;
        // vector<vector<int>>temp = dist;
        cin>>a>>b>>c;
        if(dist[a][b] <= c){
            cout<<og<<" ";
            continue;
        }
        og -= dist[a][b];
        dist[a][b] = c;
        dist[b][a] = c;
        og += dist[a][b];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] <= dist[i][a] + c +  dist[b][j]) continue;
                og -= dist[i][j];
                dist[i][j] = dist[i][a] + c +  dist[b][j];
                dist[j][i] = dist[i][j];
                og += dist[i][j];
            }
        }

        cout<<og<<" ";
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