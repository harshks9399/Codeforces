// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    map<int,multiset<int>>v;
    vector<int>index(n);
    for(int i=0;i<n;i++){cin>>index[i];}
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[index[i]].insert(x);
    }
    lli sum=0;
    for(int i=1;i<=n;i++){
        while(v[i].size()>1){
            int x = *v[i].begin();
            v[i].erase(v[i].begin());
            sum += x;
        }
    }
    cout<<sum;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--)
        solve();
    return 0;
}