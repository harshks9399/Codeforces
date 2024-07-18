// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n = 3;
    int flag1 = 0;
    int flag2 = 0;
    while(n--){
        char x;
        cin>>x;
        if(x=='R') flag1= 1;
        if(flag1==1 && x=='M') flag2=1;
    }
    if(flag2)
        cout<<"YES";
    else cout<<"NO";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
        while(t--)
        solve();
    return 0;
}