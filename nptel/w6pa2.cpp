/*
 Author : Harsh Kumar Singh
 created at : 2024-09-04 21:41:10
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

bool fun_sort(pair<lli, pair<lli,lli>>p1, pair<lli, pair<lli,lli>>p2){

    if(p1.first != p2.first) return p1.first > p2.first;
    if(p1.second.first != p2.second.first) return p1.second.first < p2.second.first;
    return p1.second.second > p2.second.second;

}



void solve(){
    int n,m,T;
    cin>>n>>m>>T;
    vector<vector<lli>>dist(n, vector<lli>(n, INT_MAX/10));
    while(m--){
        lli a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for(int i=0;i<n;i++) dist[i][i] = 0;

    //Flyod Warshall:
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = dist[i][j] < dist[i][k] + dist[k][j] ? dist[i][j] : dist[i][k] + dist[k][j];
            }
        }
    }


    // cout<<"dist***\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<dist[i][j]<<" ";
    //     cout<<"\n";
    // }
    // cout<<"****\n";



    vector<pair<lli, pair<lli,lli>>>ans;
    for(int i=0;i<n;i++){
        lli tt = 0;
        lli cnt = 0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(dist[i][j] > T) continue;
            cnt++;
            tt += dist[i][j];
        }
        ans.push_back( mp(cnt, mp(tt, i)) );
    }

    sort(ans.begin(), ans.end(), fun_sort);
    // cout<<"****\n";
    // for(auto it: ans){
    //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";

    // }

    cout<<ans[0].second.second<<"\n";
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}