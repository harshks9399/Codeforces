// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int lb = *max_element(v.begin(), v.end());
    int mb = lb+ k;

    // binary search
    int ans = lb;
    while(lb <= mb){
        
        int target = (lb+ mb)/2;
        bool flag = false;
        
        // cout<<"Looking for target " << target <<"\n";
        for(int i=0;i<n;i++){

            if(v[i] >= target) {
                flag = true;
                break;
            }
            if(i==n-1) break;
            int c_used = 0;
            c_used += target - v[i];
            if(c_used > k) continue;
            // cout<<"num = "<< v[i] <<"\tc_used = "<<c_used<<"\n";
            int tt = target-1;
            for(int j=i+1;j<n;j++){
                if(v[j] >= tt){
                    flag = true;
                    break;
                }
                c_used += tt - v[j];
                tt--;
                // cout<<"num = "<< v[j] <<"\tc_used = "<<c_used<<"\n";
                if(c_used > k) {
                    // cout<<"BREAKING out\n";
                    break;
                }
            }
        }
        if(flag){
            lb = target+1;
            ans = target;
            // cout<<"Setting answer "<<ans<<"\n";
        }else{
            mb = target-1;
        }
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