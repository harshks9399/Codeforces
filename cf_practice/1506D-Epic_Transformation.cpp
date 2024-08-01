// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    unordered_map<int,int>check;
    for(int it:a)
        check[it]++;
    
    multiset<pair<int,int>>sol;
    for(auto it:check)
        sol.insert({it.second,it.first});
    
    while(sol.size() > 1){
        pair<int,int>first = *sol.begin();
        pair<int,int>last = *sol.rbegin();
        sol.erase(first);
        sol.erase(last);
        
        if(first.first!=1)
            sol.insert({first.first-1,first.second});
        if(last.first!=1)
            sol.insert({last.first-1,last.second});
    }
    if(sol.size() == 0) cout<<0<<endl;
    else
        cout<<sol.begin()->first<<endl;
    return ;
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