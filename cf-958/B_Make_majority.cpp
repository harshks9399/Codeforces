// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>v;
    int last = -2;
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        if(x=='1'){
            v.push_back(1);
            last = 1;
        }
        else{
            if(last==0) continue;
            v.push_back(-1);
            last = 0;
        }
    }
    lli sum = 0;
    for(int it:v)
        sum += it;
    if(sum > 0) cout<<"YES\n";
    else cout<<"NO\n";
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