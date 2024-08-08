// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int solve(){
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;

    int s1 = min(a1,a2);
    int s2 = a1+a2-s1;
    int w1 = min(b1,b2);
    int w2 = b1+b2-w1;

    // if(s1 > w2) return 4;
    // if(w1 >= s2) return 0;

    if(s2 > w2){
        if(s1 <= w1) return 0;
        if(s1 < w2) return 2;
        return 4;
    }else{
        if(s1 > w1) return 2;
        return 0;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        cout<<solve()<<"\n";
    return 0;
}