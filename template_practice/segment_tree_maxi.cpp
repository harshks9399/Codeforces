#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
vector<int>t(4*N);
vector<int>v;


void build(int node, int L, int R){
    if(L==R){
        t[node] = v[L];
        return;
    }

    int M = (L+R)/2;
    build(2*node, L, M);
    build(2*node + 1, M+1, R);
    t[node] = max(t[2*node], t[2*node + 1]);
    return;
}

int find(int node , int l, int r, int L, int R){
    if(l > R || r < L) return 0;  // need to handle this case specfically when needed
    if(l <= L && r >= R) return t[node];

    int M = (L+R)/2;
    return max(find(2*node, l, r, L, M), find(2*node + 1, l, r, M+1, R)); 
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    build(1, 0, n-1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<find(1, a, b, 0, n-1)<<"\n";
    }
    return 0;
}