// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

stack<int>ans_st;

void dfs(int index, vector<int>&check_all, vector<int>&check, map<int,vector<int>>&edge, stack<int>&progress, int par, int &ans){
    if(ans) return;
    check_all[index] = 1;
    check[index] = 1;
    for(int it:edge[index]){
        if(it==par) continue;
        if(check[it]==1){
            // cycle found
            ans = 1;
            progress.push(it);
            ans_st = progress;
            // cout<<"HERE\n"<<it<<" "<<par<<"\n";
            // while(progress.size()!=0){
            //     cout<<progress.top()<<" ";
            //     progress.pop();
            // }
            // cout<<endl;
            return;
        }
        progress.push(it);
        dfs(it, check_all, check, edge, progress, index, ans);
        if(ans) return;
        progress.pop();
    }

    

}



void solve(){
    int n,m;
    cin>>n>>m;
    map<int,vector<int>>edge;
    while(m--){
        int x,y;cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    int ans  = 0;
    vector<int>check_all(n+1);
    vector<int>check(n+1);
    stack<int>progress;


    for(int i=1;i<=n;i++){
        if(ans==1) break;
        if(check_all[i]==1) continue;
        while(progress.size()!=0) progress.pop();
        progress.push(i);
        dfs(i, check_all, check, edge, progress,-1,ans);
        if(ans!=0) break;
    }

    if(ans==0){
        cout<<"IMPOSSIBLE\n";
        return ;
    }

    unordered_set<int>num_check;
    vector<int>op;
    while(1){
        int top = ans_st.top();
        ans_st.pop();
        op.push_back(top);
        if(num_check.find(top)==num_check.end()) num_check.insert(top);
        else break;
    }
    cout<<op.size()<<"\n";
    for(int it:op) cout<<it<<" ";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}