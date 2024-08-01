// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));

    int op_count = 0;
    vector<int>op_type;
    vector<int>op_loc;
    int sum = 0;
    for(int i=n-1;i>=0;i--){
        op_type.push_back(1);
        op_loc.push_back(i+1);
        for(int j=0;j<n;j++)
            v[i][j] = j+1;
        
        op_type.push_back(2);
        op_loc.push_back(i+1);
        for(int j=0;j<n;j++)
            v[j][i] = j+1;
    }

    for(auto vec:v)
        for(int it:vec)
            sum += it;
    cout<<sum<<" "<<op_type.size()<<"\n";
    for(int i=0;i<op_type.size();i++){
        cout<<op_type[i]<<" "<<op_loc[i]<<" ";
        for(int k=1;k<=n;k++)
            cout<<k<<" ";
        cout<<"\n";
    }
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