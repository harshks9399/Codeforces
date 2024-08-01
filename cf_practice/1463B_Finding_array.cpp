// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long int>a(n);
    long long int  S = 0;
    long long int S1 = 0, S2 = 0;
    for(int i=0;i<n;i++)
        cin>>a[i];

    vector<long long int>ans1(n),ans2(n);
    for(int i=0;i<n;i++){
        S = S + a[i];
        if(i%2==0){
            ans1[i]=a[i];
            ans2[i]=1;
            S2 += a[i]-1;
        }
        else{
            ans1[i]=1;
            ans2[i]=a[i];
            S1 += a[i]-1;
        }
    }
    if(2*S1 <= S){
        for(int it: ans1)
            cout<<it<<" ";
    }else{
        for(int it: ans2)
            cout<<it<<" ";
    }
    cout<<endl;
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