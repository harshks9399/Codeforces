// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const lli MOD = 1e9 + 7;

lli power10(int x){
    lli ans = 1;
    for(int i=0;i<x;i++)
        ans = (ans*10)%MOD;
    return ans;
}

lli num1(lli l, lli r){
    lli store1 = 1, store2 =1;
    lli pow2 = 1;
    for(int i=0;i<r;i++){
        if(i==l-1)
            store1 = pow2;
        if(i==r-1)
            store2 = pow2;
        pow2 = (pow2*2)%MOD;
    }
    lli check =  (store2 - store1);
    if(check<0)
        check = MOD + check;
    return check;
}

void solve(){
    int l,r,k;
    // cin>>l>>r>>k;


    l = 1;
    r = 2;
    k = 3;

    if(k==1){
        lli ans = 0;
        lli sum = 0;
        while(l!=r){
            sum = (power10(l+1)  -power10(l)) % MOD;
            ans = (ans + sum) % MOD;
            l++;
        }
        cout<<ans<<endl;
        return ;
    }
    int low_ans = 0 ;
    if(l==0 && k<10){
        int a = 2;
        while(k*a < 10){
            low_ans++;
            a++;
        }
    }
    lli high_ans = num1(l,r);
    lli ans = (low_ans+high_ans)%MOD;
    cout<<ans<<endl;
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