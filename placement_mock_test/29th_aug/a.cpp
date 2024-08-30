/*
 Author : Harsh Kumar Singh
 created at : 2024-08-29 21:03:58
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>v(n);
    for(int &it : v) cin>>it;
    sort(v.begin(), v.end());
    multiset<int>check;
    for(int it: v) check.insert(it);
    vector<int>k(n);
    for(int i=0;i<n;i++) k[i] = v[i]/b;

    


    int ans = v[0];
    int l = v[0], r = v[n-1];
    while(l<=r){
        int mid = (l+r)/2;
        bool good = true;

        int index = distance(check.begin(), check.lower_bound(mid));
        int need =0 , have = 0;
        int mini = INT_MAX;
        for(int i=0;i<index;i++){
            // to cover at least  mid - v[i]
            int temp = mid - v[i];
            int x = 0;
            x = temp/a;
            if(temp%a!=0) x++;
            need += x;
            mini = min(mini , v[i] + a*x);
        }

        for(int i=index;i<n;i++){
            int temp = v[i] - mid;
            have += temp/b;
        }

        if(have < need) good = false;
        if(good){
            ans = max(ans, mini);
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout<<ans<<"\n";
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t = 1;
    while(t--)
        solve();
    return 0 ;
}