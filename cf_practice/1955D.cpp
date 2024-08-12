// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int>a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    
    multiset<int>todo, done, extra;
    for(int it: b) todo.insert(it);
    int ans = 0;
    for(int i=0;i<m;i++){
        if(todo.find(a[i])!= todo.end()){
            todo.erase(todo.find(a[i]));
            done.insert(a[i]);
        }else{
            extra.insert(a[i]);
        }
    }

    ans += (done.size() >= k );


    for(int i=m;i<n;i++){
        int l = i-m;
        int r = i;

        if(extra.find(a[l])!= extra.end()) extra.erase(extra.find(a[l]));
        else{
            done.erase(done.find(a[l]));
            todo.insert(a[l]);
        }
        if(todo.find(a[i])!= todo.end()){
            todo.erase(todo.find(a[i]));
            done.insert(a[i]);
        }else{
            extra.insert(a[i]);
        }
        ans += (done.size() >= k);
    } 
    cout<<ans<<"\n";
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