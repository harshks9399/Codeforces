// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    bool zero = false;
    lli tot = 0;
    for(int i=0;i<n;i++){
        string a = "";
        char c;
        cin>>c;
        a += c;
        v[i] = stoi(a);
        // if(!v[i]) zero = true;
        tot += v[i];
    }
    if(n<=2){
        if(n==2) cout<<10*v[0] + v[1]<<"\n";
        if(n==1) cout<<v[0]<<"\n";
        return;
    }
    // if(zero) {
    //     cout<<"0\n";
    //     return;
    // }
    lli ans = INT_MAX;
    for(int i=0;i<n-1;i++){
        // 10v[i] + v[i+1]]
        tot = 0;
        for(int j=0;j<n;j++){
            if(j==i){
                int x =  10*v[j] + v[j+1];
                if(x!=1) tot += x;
                else tot = tot==0 ? 1: tot;
                j++;
                continue;
            }
            if(v[j]==0) {tot = 0; break;}
            if(v[j]==1) continue; 
            else tot += v[j];
        }
        // cout<<"tot = "<<tot<<"\n";
        ans = ans < tot ? ans : tot;
        if(ans==0) break;
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