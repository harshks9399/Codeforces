// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,x;
    cin>>n>>x;
    multiset<int>v;
    map<int,vector<int>>pos;
    while(n--){
        int a;cin>>a;
        v.insert(a);
        pos[a].push_back(v.size());
    }
    for(int it:v){
        int rem = x-it;
        v.erase(v.find(it));
        if(v.find(rem)!=v.end()){
            if(rem==it) cout<<pos[it][0]<<" "<<pos[it][1]<<"\n";
            else  cout<<pos[it][0]<<" "<<pos[rem][0]<<"\n";
            return;
        }
        v.insert(it);
    }
    cout<<"IMPOSSIBLE";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}