// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;

    map<int,lli>val;
    // map<int,vector<int>>lvl;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        val[i]= x;
    }

    map<int,int>par;
    map<int,vector<int>>child;
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        par[i] = p;
        child[p].push_back(i);
    }

    vector<int>leaves;
    stack<int>st;
    st.push(1);
    int lvl_cnt = 1;
    // lvl[1] = 1; 
    while(st.size()!=0){
        int top = st.top();
        st.pop();
        if(child[top].size()!=0)
            for(int it:child[top]){ 
                st.push(it);
                // lvl[it] = lvl[top] + 1;
                // lvl_cnt = max(lvl_cnt, lvl[it]);
            }
        else leaves.push_back(top);
    }


    vector<lli>score(n+1,2e9);
    for(int i=1;i<=n;i++) score[i] =val[i];
    for(int it:leaves) {score[it] = val[it];st.push(it);}

    while(st.size()!=0){
        int top = st.top();
        st.pop();
        if(top==1) continue;

        int p = par[top];
        if(score[top] <= val[p]) score[p] = score[p] < score[top] ? score[p] : score[top];
        else{
            float diff = score[top] - val[p];
            int diffn = ceil(diff/2);
            score[top] = score[top] - diffn;
            score[p] = score[p] + diffn;
            score[p] = score[p] < score[top] ? score[p] : score[top];
        }
    }
    score[1] = 2e9;
    for(int it:child[1]){
        score[1] = min(score[1], score[it]);
    }
    cout<<score[1] + val[1]<<"\n";
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