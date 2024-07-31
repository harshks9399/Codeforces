// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    string s;
    cin>>s;


    char prev = '#';
    int curr=1;
    int ans =1;
    for(char c:s){
        if(c==prev){
            curr++;
            ans = max(curr,ans);
        }
        else curr=1;
        prev = c;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}