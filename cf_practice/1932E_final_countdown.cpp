// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        string xx="";
        char x;cin>>x;
        xx += x;
        v[i] = stoi(xx);
    }
    vector<int>ans;
    vector<int>sum(n,0);
    for(int it:v) sum[0]+=it;
    
    for(int i=1;i<n;i++)
        sum[i] = sum[i-1] - v[n-i];

    // for(int it:sum)
    //     cout<<it<<"\n";

    int carry = 0;
    for(int i=0;i<n;i++){
        int x = (sum[i] + carry) % 10 ; 
        ans.push_back(x);
        carry = (sum[i] + carry) / 10;
    }
    while(carry!=0){
        int x = carry % 10;
        ans.push_back(x);
        carry = carry /10;
    }
    int flag=0;
    int m = ans.size();
    for(int i=m-1;i>=0;i--){
        if(ans[i]==0 && flag==0) continue;
        flag=1;
        cout<<ans[i];
    }
    cout<<"\n";
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