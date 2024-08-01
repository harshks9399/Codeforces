// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> solve(int n){
    unordered_set<int>check,ans;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i%2==0) check.insert(i);
            if( (n/i)%2==0 ) check.insert(n/i);    
        }
    }
    for(int it:check)
        ans.insert(1 + it/2);
    return ans;
}

void solve(){
    int n,x;
    cin>>n>>x;
    unordered_set<int>a = solve(n-x), b = solve(n+x-2);
    for(int it:b) a.insert(it);

    int ans = 0;
    for(int it:a) if(it >= x) ans++;
    cout<<ans<<"\n";
    return ;
    // number of even divisors of n-x

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