// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>> a[i];
    unordered_set<int>check;
    for(int it:a)
        check.insert(it);
    if(check.size()>k){
        cout << -1 << endl;
        return;
    }
    int num = 1;
    while(check.size()!=k){
        check.insert(num);
        num++;
    }
    cout<<n*k<<endl;
    while(n--){
        for(int it:check)
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