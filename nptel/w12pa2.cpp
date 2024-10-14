/*
 Author : Harsh Kumar Singh
 created at : 2024-10-14 17:42:21
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int row[4] = {1,0,-1,0};
int col[4] = {0,-1,0,1};

void dfs(vector<vector<ll>>&v, vector<vector<int>>&h, int i, int j, int curr, int &maxi){
    // maxi = max(maxi, curr);
    int temp = 0;
    for(int k=0;k<4;k++){
        int r = i + row[k];
        int c = j + col[k];
        if(r<0 || c<0 || r>=v.size() || c >=v[0].size()) continue;
        if(v[i][j] <= v[r][c]) continue;
        if(h[r][c]==0) dfs(v,h,r,c,1,maxi);
        temp = max(temp, h[r][c]);
    }
    h[i][j] = curr + temp;
    maxi = max(maxi, h[i][j]);
}





int solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll>>a(n, vector<ll>(m));
    vector<vector<ll>>b(n, vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) 
            cin>>a[i][j];
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++) 
    //         cin>>b[i][j];
    // }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++) 
            cin>>b[i][j];
    }

    vector<vector<int>>ah(n, vector<int>(m)),  bh(n,vector<int>(m));
    int maxia = 1;
    int maxib = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int curr = 1;
            if(ah[i][j]==0){
                curr = 1;
                ah[i][j]=1;
                dfs(a,ah,i,j,curr, maxia);
            }
            if(bh[i][j]==0){
                curr = 1;
                bh[i][j]  =1;
                dfs(b,bh,i,j,curr, maxib);
            }
        }
    }

    /*Checking matrices*/
    // for(auto &v: a){
    //     for(auto &it: v) cout<<it<<" ";
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // for(auto &v : ah){
    //     for(auto  &it:v) cout<<it<<" ";
    //     cout<<'\n';
    // }
    // cout<<"\n";

    // for(auto &v: b){
    //     for(auto &it: v) cout<<it<<" ";
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // for(auto &v : bh){
    //     for(auto &it:v) cout<<it<<" ";
    //     cout<<'\n';
    // }
    // cout<<"\n";


    if(maxia > maxib) return 1;
    else if(maxia==maxib) return 0;
    else return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        cout<<solve()<<"\n";
    return 0;
}