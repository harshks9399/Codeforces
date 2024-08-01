// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int


vector<lli>fib;

void fib_fun(){
    fib.push_back(1);
    fib.push_back(1);
    lli a,b;
    a= 1;
    b= 1;
    for(int i=0;i<1002;i++){
        lli c = a+b > 1003 ? 1003 : a+b ;
        a = b;
        b = c;
        fib.push_back(c);
    }
}

void solve(){
    int n;
    cin>>n;
    for(int x=1;x<=n;x++){
        lli y = fib[x-1] > n ? n : fib[x-1];
        cout<<x<<" "<<y<<"\n";
    }
    cout<<"\n";
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    fib_fun();
    while(t--)
        solve();
    return 0;
}