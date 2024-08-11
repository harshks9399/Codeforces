// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int N = 2e5+1;
vector<lli>pre(N,0);
lli calc(int x){
    lli ans = 0;
    while(x!=0) {
        ans ++;
        x = x/3;
    }
    return ans;
}


void fix(){
    pre[0] = 0;
    pre[1] = calc(1);
    for(int i=2;i<N;i++){
        pre[i] = pre[i-1] + calc(i);
    }
    return;
}

void solve(){
    int l,r;
    cin>>l>>r;


    cout<<pre[r] - pre[l-1] + calc(l)<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fix();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}