#include <bits/stdc++.h>
using namespace std;
 
bool check_function(pair<int,int>a, pair<int,int>b){
    if(a.first!=b.first) return a.first < b.first;
    return a.second > b.second;
}
 
 
int main()
{
    
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    map<pair<int,int>, int>pos;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        v[i] = make_pair(l,r);
        pos[(v[i])] = i;
    }
    sort(v.begin(), v.end(), check_function);
    vector<int>contains(n), contained(n);
    // the first element is contained by none
    int l = v[0].first, r = v[0].second;
    
    for(int i=1;i<n;i++){
        auto interval = v[i];
        int li = interval.first, ri = interval.second;
        
        if(li >= l && ri<=r) {
            contained[pos[v[i]]] = 1;
            contains[pos[make_pair(l,r)]]=1;
        }else{
            l = li;
            r = ri;
        }
    }
    int minend = 2e9;
    
    for(int i=n-1;i>=0;i--){
        auto interval = v[i];
        int r = v[i].second;
        
        if(r >= minend) contains[pos[v[i]]] = 1;
        else minend = r;
    }
    
    for(int it:contains) cout<<it<<" ";
    cout<<"\n";
    for(int it:contained) cout<<it<<" ";
    
    
    
    
    
    
    
    
    
    
    return 0;
}