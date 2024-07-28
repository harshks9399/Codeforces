// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    int t = 0;
    int ans = 0;
    int curr = 0;

    vector<pair<int,int>>timeings(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        timeings[i] = make_pair(a,b);
    }
    sort(timeings.begin(), timeings.end());

    multiset<int>leave;


    for(auto it:timeings){
        // ans = max(ans, curr);
        int a,b;
        a = it.first;
        b = it.second;
        // cin>>a>>b;
        curr++;
        // ans = max(ans, curr);
        t = a;
        while(!leave.empty() && *leave.begin() < t){
            leave.erase(leave.begin());
            curr--;
        }
        ans = max(ans, curr);
        leave.insert(b);
    }

    // cout<<"__________________________________\n\n";
    // for(auto it:timeings)
    //     cout<<it.first<<" "<<it.second<<"\n";
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}