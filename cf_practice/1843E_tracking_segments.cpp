// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    // cout<<"HERE\n";
    int n,m,q;
    cin>>n>>m;
    vector<int>v(n), queries;
    vector<pair<int,int>>range;
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        range.push_back({l,r});
    }

    cin>>q;
    while(q--){
        int x;
        cin>>x;
        queries.push_back(x);
    }
    q = queries.size();

    vector<int>temp = v;
    for(int it: queries) temp[it-1] = 2;
    bool flag = false;
    for(auto it: range){
        int  l = it.first, r = it.second;
        int sum = -1 * (r-l + 1);
        for(int j=l-1;j<=r-1;j++) sum += temp[j];
        if(sum > 0) flag = true;
    }
    if(!flag){
        cout<<"-1\n";
        return;
    }
    int ans  = q;

    int lb = 1;
    int ub = q;
    while(lb <= ub){
        bool good = false;
        int target = (lb+ ub)/2;
        // cout<<"Looking for target = "<<target<<"\n";

        vector<int>t = v;
        for(int i=0;i<target;i++)
            t[queries[i]-1] += 2;
        
        for(auto it:range){
            int l = it.first, r =it.second;
            int sum = -1 * (r-l+1);
            for(int i=l-1;i<=r-1;i++)
                sum += t[i];
            if(sum > 0 ){ 
                good = true;
                // cout<<"found sum > 0 at for range = "<<l<<" "<<r<<"\n"; 
                break;
            }
        }

        if(good){
            ans = target;
            ub = target-1;
        }else lb = target+1;
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