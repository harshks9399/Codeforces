/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 23:29:34
*/
//TEMPLATES : ft, expo, gcd, seive
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    int g; cin>>g;
    vector<lli>a(g);
    for(lli &it: a) cin>>it;
    sort(a.begin(), a.end());
    multiset<lli>score;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l = j, r = m-j+1;
            int col = min(k, min(l,r));
            l = i ;
            r = n-i+1;
            int row = min(k, min(l,r));
            int temp = -1 * row * col;
            score.insert(temp);
        }
    }
    lli ans  =0;
    int idx = g-1;
    for(int it: score){
        it *= -1;
        ans  += a[idx]*it;
        idx--;
        if(idx<0) break;
    }
    cout<<ans<<"\n";
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