/*
 Author : Harsh Kumar Singh
 created at : 2024-08-16 21:37:40
*/
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int a,b,x,y;
    cin>>a>>b>>x>>y;

    if(a > x){
        swap(a,x);
        swap(b,y);
    }

    if( b  <  x){
        cout<<1<<"\n";
        return;
    }

    if(a <= x && y <= b){
        int ans = y-x;
        if(a < x) ans++;
        if(y < b) ans++;
        cout<<ans<<"\n";
        return;
    }
    int ans = 0;
    if(a < x) ans ++;
    ans += b-x;
    if(b < y) ans ++;
    cout<<ans<<"\n";
    return;
    // int flag = 0;
    // int ans = 0;
    // for(int i=0;i<100;i++){
    //     if(i==a || i==b || i==x || i==y) flag = (flag == 0);
    //     if(flag) ans++;
    // }

    // cout<<ans<<"\n";
    // return;

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