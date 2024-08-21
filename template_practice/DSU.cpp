/*
 Author : Harsh Kumar Singh
 created at : 2024-08-21 19:35:12
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string)
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 1e5;
vector<int>par(N,-1);
vector<int>rank_(N,0);

void make_set(int a){
    par[a]= a;
    rank_[a] = 0;
}
int find_par(int x){
    if(par[x]==x) return x;
    return par[x] = find_par(par[x]);
}

void join(int a, int b){
    a = find_par(a);
    b = find_par(b);
    if(a==b) return;
    if(rank_[a] < rank_[b]) swap(a,b);
    par[b] = a;
    if(rank_[a]==rank_[b]) rank_[a]++;
}


void solve(){
    int n;
    cin>>n;
    stack<pair<int,int>>q;
    for(int i=1;i<=n;i++) make_set(i);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        if(find_par(a)==find_par(b)) q.push(make_pair(a,b));
        join(a,b);
    }
    int ans = 0;
    multiset<int>check;
    int M = find_par(1);
    stack<int>q2;
    for(int i=1;i<=n;i++){
        int x = find_par(i);
        if(check.find(x)==check.end()) {
            check.insert(x);
            ans++;
            if(x==M) continue;
            else q2.push(x);
        }   
    }   
    ans--;
    cout<<ans<<"\n";
    while(ans!=0){
        auto t1 = q.top();
        int x = q2.top();
        q.pop();
        q2.pop();
        ans--;
        cout<<t1.first<<" "<<t1.second<<" "<<M<<" "<<x<<"\n";
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