// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    multiset<int>check;
    int ans = 1;
    int i=0,j=0;
    while(j<n){

        // for(int it:check){
        //     cout<<it<<" ";
        // }
        // cout<<"\t\t"<<i<<" "<<j<<"\n";
        // // cout<<"\n";

        if(i==j){
            check.insert(v[i]);
            j++;
            continue;
        }

        if(check.find(v[j])!=check.end()){
            while(v[i]!=v[j]) {
                check.erase(v[i]);
                i++;
            } 
            i++;
            j++;
            //check.erase(v[j]);
            ans = ans > check.size() ? ans : check.size(); 
        }else{
            check.insert(v[j]);
            ans = ans > check.size() ? ans : check.size(); 
            j++;
        }
    }
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