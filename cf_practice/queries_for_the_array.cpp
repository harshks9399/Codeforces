// THE BASIC SNIPPET
// We have template for fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    ll n = s.size();
    ll cnt = 0;
    stack<pair<ll, ll>>st;
    pair<ll, ll> temp;
    for(char c:s){
        if(c=='+'){
            cnt++;
        }

        if(c=='-') {
            if (st.size() > 0)
            {
                temp = st.top();
                if (temp.second == 0)
                {
                    if (temp.first == cnt)
                        st.pop();
                }
                else
                {
                    if (temp.first == cnt)
                    {
                        st.pop();
                        temp.first--;
                        st.push(temp);
                    }
                }
            }
            cnt--;
        }
        if(c=='1'){
            if (st.size() > 0)
            {
                temp = st.top();
                if(temp.second == 0)
                {
                    cout << "NO\n";
                    return;
                }
                else
                {
                    st.pop();
                    temp.first = cnt;
                    st.push(temp);
                }
            }
            else
                st.push({cnt, 1});
        }

        if(c=='0'){
            if (cnt < 2)
            {
                cout << "NO\n";
                return;
            }
            if (st.size() > 0)
            {
                temp = st.top();
                if(temp.second == 0)
                {
                    st.push({cnt, 0});
                }
                else if (temp.first == cnt)
                {
                    cout << "NO\n";
                    return;
                }
            }
            else
                st.push({cnt, 0});
        }
    }
    cout<<"YES\n";
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