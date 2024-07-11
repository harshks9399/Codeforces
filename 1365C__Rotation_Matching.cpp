// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    unordered_map<int,int>aloc, bloc, sol;
    for(int i=0;i<n;i++){
        aloc[a[i]] = i;
        bloc[b[i]] = i;
    }


    for(int i=0;i<n;i++){
        int diff = aloc[b[i]] - i;
        if(diff < 0)
            diff = n + diff;
        sol[diff]++;
    }
    int ans = 0;
    for(auto it : sol){
        if(it.second > ans)
            ans = it.second;
    }
    

    cout<<ans<<endl;
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