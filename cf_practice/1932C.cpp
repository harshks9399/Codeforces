// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int &it: a) cin>>it;

    string s;
    cin>>s;
    stack<int>st;
    int i =0, j= n-1;
    for(char c:s){
        if(c=='L'){
            st.push(a[i]);
            i++;
        }else{
            st.push(a[j]);
            j--;
        }
    }

    lli prod = 1;
    vector<lli>ans;

    while(st.size()!=0){
        int top = st.top();
        st.pop();
        prod = prod * top;
        prod %= m;
        ans.push_back(prod);
    }

    reverse(ans.begin(), ans.end());
    for(lli it: ans) cout<<it<<" ";
    cout<<"\n";
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