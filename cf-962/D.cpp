// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

string calc(int a, int b){
    string ans = "";
    ans += to_string(a);
    ans += to_string(b);
    // ans += to_string(c);
    return ans;
}


void dfs(int a,int b,  unordered_set<string> &count , int x, int n, int &ans){
    string str = calc(a,b);

    int xc = x-a-b;
    int nc = (n-(a*b))/(a+b);
    int lim = min(xc,nc);
    if(lim <= 0 ) return;
    ans++;
    dfs(a,b+1,count,x,n,ans);
    dfs(a+1,b,count,x,n,ans);
    return;
    
}

int solve(){
    int n,x;
    cin>>n>>x;
    unordered_set<string> count ;
    int ans = 0;
    dfs(1,1,count, x, n,ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        cout<<solve()<<"\n";
    return 0;
}