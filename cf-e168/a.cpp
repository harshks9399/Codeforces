// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    string s;
    cin>>s;
    multiset<char>all;
    for(int i='a';i<='z';i++) all.insert(char(i));
    if(s.size()==1){
        all.erase(s[0]);
        s += *all.begin();
        cout<<s<<"\n";
        return;
    }

    int loc = s.size();
    char prev ='A';
    for(int i=0;i<s.size();i++){
        if(prev==s[i]){
            loc = i;
            break;
        }
        prev = s[i];
    }
    if(loc==s.size()){
        all.erase(s[s.size()-1]);
        s += *all.begin();
        cout<<s<<"\n";
        return;
    }


    all.erase(s[loc]);
    string ans = "";
    for(int i=0;i<s.size();i++){
        if(i==loc){
            ans += *all.begin();
        }
        ans += s[i];
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