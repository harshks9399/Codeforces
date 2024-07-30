// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;cin>>n;
    // int nl =0 , nn = 0; nr = 0;
    string s;cin>>s;
    // vector<int>v(6);
    // for(int i=0;i<n;i++){
    //     char x;cin>>x;
    //     if(x=='(') {v[i] = -1; nl++;}
    //     else if(x==')') {v[i] = 1; nr++;}
    //     else nn++;
    // }
    stack<pair<char,int>>st;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(st.size()==0){
            st.push({s[i],i});
            continue;
        }

        if(s[i]=='(') st.push({s[i],i});
        else if(s[i]==')'){
            if(st.top().first=='(' || st.top().first=='_') {
                ans += (i - st.top().second) ;
                st.pop();
            }
            else st.push({s[i],i});
        }
        else{
            if(st.top().first=='(') 
            {
                ans += (i - st.top().second) ;
                st.pop();
            }
            else st.push({s[i],i});
        }
    }
    cout<<ans<<"\n";
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