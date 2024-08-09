// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

vector<int>check(26,0);
vector<char>path;

void dfs(int x, int k){
    while(check[x] < k){
        int next = check[x];
        check[x]++;
        dfs(next, k);
        path.push_back(char(int('a') + next));
    }
}
 


void solve(){
    int n,k;
    cin>>n>>k;
    dfs(0, k);
    string ans = "";
    path.push_back('a');
    for(int i=0;i<n;i++){
        ans += path[  i % path.size()  ];
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}