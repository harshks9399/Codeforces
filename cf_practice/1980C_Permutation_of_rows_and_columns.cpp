// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>a, int n, int m){
    vector<vector<int>> b(m, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            b[j][i] = a[i][j];
    return b;  
}

bool check(vector<vector<int>>&a, vector<vector<int>>&b){
    int n = a.size();
    int m = a[0].size();
    map<int, unordered_set<int>>vec_check;
    for(int i=0;i<n;i++){
        int x = *min_element(a[i].begin(), a[i].end());
        for(int j=0;j<m;j++)
            vec_check[x].insert(a[i][j]);
    }
    for(int i=0;i<n;i++){
        int x = *min_element(b[i].begin(), b[i].end());
        for(int j=0;j<m;j++){
            if(vec_check[x].find(b[i][j])==vec_check[x].end())
                return false;
        }
    }
    return true;
}



void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> b[i][j];
    
    if(!check(a,b)){
        cout<<"NO\n";
        return;
    }
    a = transpose(a,n,m);
    b = transpose(b,n,m);
    if(!check(a,b)){
        cout<<"NO\n";
        return;
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