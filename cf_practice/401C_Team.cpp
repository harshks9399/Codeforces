// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m,n;
    cin>>n>>m; 
    // n = #0
    // m = #1

    if(n-m>1){
        cout<<"-1"<<endl;
        return;
    }
    if(m > 2*n + 2  ){
        cout<<"-1"<<endl;
        return;
    }    

    vector<int>sol(1,-1);
    for(int i=0;i<min(m,n);i++){
        sol.push_back(1);
        sol.push_back(0);
    }
    if(m>n){
        sol.push_back(1);
    }
    else if(n>m){
        sol[0] = 0;
    }
    m = m - min(m,n) - 1;
    int pos = 1;
    while(m>0){
        sol[pos] = 11;
        m--;
        pos+=2;
    }
    for(int it:sol){
        if(it!=-1)
        cout<<it;
    }
    cout<<endl;
    return;


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t=1;
    while(t--)
        solve();
    return 0;
}