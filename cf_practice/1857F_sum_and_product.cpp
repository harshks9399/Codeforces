// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    vector<lli>v(n);
    for(int i=0;i<n;i++) cin>>v[i];


    // unordered_map<lli,lli>m;
    map<lli,lli>m;
    for(lli it:v) m[it] ++ ;

    int q;
    cin>>q;
    vector<pair<lli,lli>>queries;
    while(q--){
        lli x,y;
        cin>>x>>y;
        queries.push_back({x,y});
    }
    
    for(auto it:queries){
        lli x = it.first, y = it.second;
        lli ans = 0;
        // a + b = x;
        // |a - b| = sqrt(x^2 - 4y)
        lli D = x*x - 4*y;
        if(D<0){
            cout<<"0 ";
            continue;
        }
        D = sqrt(D);
        lli ai = (x+D)/2;
        lli aj = (x-D)/2;

        if(ai+aj==x && ai*aj==y){
            if(ai==aj){
                if(m[ai]==0) ans = 0;
                else ans =  (m[ai]* (m[ai]-1))/2;
            } 
            else ans = m[ai] * m[aj];
        }
        cout<<ans<<" ";
        continue;

    }
    cout<<"\n";
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