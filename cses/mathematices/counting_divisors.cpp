/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 14:07:58
*/
//TEMPLATES : ft, expo, gcd, seive
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int N = 1e5 + 1;
vector<bool>prime(N,true);

void prime_setup(){ // O(n lg lg n )
    prime[0] = false;
    prime[1] = false;

    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i; j<N ; j += i) prime[j] = false;
        }
    }
}

lli solve(){
    int n;
    cin>>n;
    if(n==1) return 1;
    map<int,int>div;
    for(int i=2; i*i<=n ; i++){
        if(!prime[i]) continue;
        if(n%i!=0) continue;
        while(n%i==0){
            div[i]++;
            n /= i;
        }
    }
    if(n > 1) {
        div[n]++;
    }
    lli ans = 1;
    for(auto it: div){
        ans *= (it.second + 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    prime_setup();

    while(t--)
        cout<<solve()<<"\n";
    return 0;
}