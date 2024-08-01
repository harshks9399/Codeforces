// THE BASIC SNIPPET
// We have template for fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    string s;
    cin>>s;
    int n = s.size();

    stack<char>st;
    for(char c:s){
        if(c=='+'){
            if(st.size()==0) st.push('S');
            else st.push('-');
        }

        if(c=='-') st.pop();

        if(c=='1'){
            int count = 0;
            if(!st.empty() && st.top()=='-'){
                count++;
                st.pop();
            }
            if(!st.empty() && st.top()=='N'){
                cout<<"NO\n";
                return;
            }
            while(count--)
                st.push('S');            
        }

        if(c=='0'){
            int count = 0;
            if(st.size()<=1){
                cout<<"NO\n";
                return;
            }

            if(!st.empty() && st.top()=='-'){
                count++;
                st.pop();
            }

            if(st.size()==1){
                while(count--) 
                    st.push('N');
                continue;
            }

            if(st.top()=='S'){
                cout<<"NO\n";
                return;
            }
            // if(!st.size() && st.top()=='S'){
            //     cout<<"NO\n";
            //     return;
            // }  
        }
    }
    cout<<"YES\n";
    return;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}