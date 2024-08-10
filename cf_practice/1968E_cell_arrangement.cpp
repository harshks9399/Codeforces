// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;

    cout<<"1 1\n1 2\n";
    int cnt = n-2;

    int j = n;
    while(cnt--){
        cout<<j<<" "<<j<<"\n";
        j--;
    }

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