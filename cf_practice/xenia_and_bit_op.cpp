/*
 Author : Harsh Kumar Singh
 created at : 2024-09-04 15:26:11
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N= 1<<20 ;
vector<lli>t(N);
vector<lli>v;

void build(int node, int L, int R, int &type){
    if(L==R){
        t[node] = v[L];
        type = 1;
        return;
    }

    int M = ((R-L)/2) + L;
    int ntype = (type==0);
    build(2*node, L, M, ntype);
    build(2*node + 1, M+1, R, ntype);
    if(ntype) t[node] = t[2*node] | t[2*node + 1];
    else t[node] = t[2*node] ^ t[2*node+1];
    type = (ntype==0);
}


void update(int node, int L, int R, int &type, int pos, lli n_val){
    if(L==R){
        //v[L] = n_val;
        t[node] = n_val;
        type = 1;
        return;
    }
    int M = ((R-L)/2) + L;
    int ntype = 0;
    if(pos <= M) update(2*node, L, M, ntype, pos, n_val);
    else update(2*node + 1, M+1, R, ntype, pos, n_val);
    if(ntype) t[node] = t[2*node] | t[2*node + 1];
    else t[node] = t[2*node] ^ t[2*node+1];
    type = (ntype==0);
}




void solve(){
    int n,q;
    // lli x= 1<<30;
    // cout<<x;
    cin>>n>>q;
    n = 1  << n;
    for(int i=0;i<n;i++){
        lli x;
        cin>>x;
        v.push_back(x);
    }
    int type = 0;
    build(1,0,n-1, type);


    // for(int i=1;i<=7;i++){
    //     cout<<i<<" "<<t[i]<<"\n";
    // }
    // cout<<"****\n";

    while(q--){
        lli pos, n_val;
        cin>>pos>>n_val;
        update(1, 0, n-1, type, pos-1, n_val);
        // for(int i=1;i<=7;i++){
        //     cout<<i<<" "<<t[i]<<"\n";
        // }
        // cout<<"****\n";
        cout<<t[1]<<"\n";
    }
    return ;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}