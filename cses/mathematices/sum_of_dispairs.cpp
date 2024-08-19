/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 20:32:24
*/
//TEMPLATES : ft, expo, gcd, seive
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int N = 1e6 + 2;
const int mod = 1e9 + 7;
vector<bool>prime(N,true);
map<lli,lli>m;

void prime_setup(){
    prime[0] = prime[1] = false;
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i; j<N; j+=i) prime[j] = false;
        }
    }
}
lli expo(lli a, int b){
    lli ans = 0;
    while(b!=0){
        if(b&1) ans = (ans * a) % mod;
        b = b>>1;
        a = (a*a) % mod;
    }
    ans = ans==1 ? ans + mod : ans;
    return ans;
}


void solve(){
    lli n;
    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(n%i!=0) continue;
        while(n%i==0){
            n /= i;
            m[i]++;
        }
    }
    lli ans = 1;
    for(auto it: m){
        lli a = it.first, b = it.second;
        lli temp = expo(a,b+1);
        temp--;
        temp /= (a-1);
        ans = (ans * temp) % mod;
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime_setup();
    solve();
    return 0;
}