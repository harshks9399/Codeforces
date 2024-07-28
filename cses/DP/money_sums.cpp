// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    // vector<int>coins(n);
    multiset<int>coins;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        coins.insert(x);
    }

    set<int>start;
    start.insert(0);
    for(int it:coins){
        start.insert(0);
        set<int>curr;
        curr = start;
        for(int old:start)
            curr.insert(old+it);
        start = curr;
    }
    start.erase(0);
    cout<<start.size()<<"\n";
    for(int it:start)
    {
        if(it==0) continue;
        cout<<it<<" ";
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