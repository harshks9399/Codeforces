// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    if(n <= k){
        cout<<1<<"\n";
        return;
    }
    int mynum = k-1;
    if(mynum==1) {
        cout<<n-1<<"\n";
        return;
    }
    int sol = n/mynum;
    if(n % mynum != 0 && n%mynum!=1)
        sol++;
    cout<<sol<<"\n";
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