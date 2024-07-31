// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    if(n<=3){
        if(n==1) cout<<1<<"\n";
        else cout<<"NO SOLUTION\n";
        return;
    }

    list<int>ans;
    ans.push_back(3);
    ans.push_back(1);
    ans.push_back(4);
    ans.push_back(2);

    int count = 4;
    while(count < n){
        count++;
        if(count%2==1) ans.push_back(count);
        else ans.push_front(count);
    }

    while(ans.size()!=0){
        int x = ans.front();
        ans.pop_front();
        cout<<x<<" ";
    }
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}