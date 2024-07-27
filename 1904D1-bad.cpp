// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

// min priorityy queue
// priority_queue<int,vector<int>, greater<int>>pq;

void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    // cout<<"HERE\n";
    vector<map<int,int>>lmax(n), rmax(n);
    lmax[0][a[0]] = 0;
    rmax[n-1]a[n-1] = n-1;
    // cout<<"HERE\n";
    for(int i=1;i<n;i++){
        if(a[i] > b[i]) {cout<<"NO\n";return;}
        // cout<<"Working on "<<a[i]<<" at index = "<<i<<"\n";
        if(a[i]!=b[i]){
        lmax[i] = lmax[i-1];
        while(!lmax[i].empty()){ 
            if((*lmax[i].begin()).first() <= a[i]) lmax[i].erase(lmax[i].begin());
            else break;
        }}
        lmax[i][a[i]] = i;


        int j= n-i-1;
        // cout<<"Working on "<<a[j]<<" at index = "<<j<<"\n";
        if(a[j]!=b[j]){
        rmax[j] = rmax[j+1];
        while(!rmax[j].empty()){ 
            if((*rmax[j].begin()).first() <= a[j]) rmax[j].erase(rmax[j].begin());
            else break;
        }}
        rmax[j]a[j] = j;
    }
    // cout<<"HERE\n";
    vector<pair<int,int>>ans;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) {ans.push_back(make_pair(0,0));continue;}
        if(lmax[i].find(b[i])!=lmax[i].end()) {ans.push_back(-1,lmax[i][b[i]]);continue;}
        if(rmax[i].find(b[i])!=rmax[i].end()) {ans.push_back(1,rmax[i][b[i]]);continue;}
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) continue;
        
    }


    cout<<"YES\n";
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