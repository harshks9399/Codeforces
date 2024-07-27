// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>demand(q);
    for(int i=0;i<q;i++)
        cin>>demand[i];
    for(int i=0;i<n-1;i++){
        cout<<i+1<<" "<<i+2<<"\n";
    }

    vector<vector<int>>tree(2,vector<int>());
    for(int i=3;i<=n;i++) tree[0].push_back(i);
    for(int i=0;i<q;i++){
        //demand[i]

        // cout<<"UP = ";
        // for(int it:tree[0]) cout<<it<<" ";
        // cout<<"\nDOWN =  ";
        // for(int it:tree[1]) cout<<it<<" ";
        // cout<<"\n";

        int up_dist = tree[0].size()+1, down_dist = tree[1].size()+1;
        if(up_dist==demand[i] || down_dist==demand[i]){
            // cout<<"nothing\n";
            cout<<"-1 -1 -1\n";
            continue;
        }
        int wind = tree[0].size() < tree[1].size() ;
        int alt = (wind+1)%2;



        // cout<<"wind="<<wind<<"\nalt="<<alt<<"\n";
        if(!(demand[i]>up_dist && demand[i]>down_dist)){
            // cout<<"DEL\n";
            int v2;
            if(tree[alt].size()==0) v2=2;
            else v2 = tree[alt][tree[alt].size()-1];
            int v1 = tree[wind][demand[i]-2];
            int u = tree[wind][demand[i]-1];
            cout<<u<<" "<<v1<<" "<<v2<<"\n";

            for(int j=demand[i]-1;j<tree[wind].size();j++)
                tree[alt].push_back(tree[wind][j]);
            tree[wind].erase(tree[wind].begin()+demand[i]-1, tree[wind].end());
        }else{
            // cout<<"add\n";
            int req = demand[i] - tree[alt].size() -1;
            int uindex = tree[wind].size()-req;
            int u = tree[wind][uindex];
            int v1;
            if(uindex==0) v1=2;
            else v1 = tree[wind][uindex-1];
            int v2 = tree[alt][tree[alt].size()-1];
            cout<<u<<" "<<v1<<" "<<v2<<"\n";

            for(int j=uindex;j<tree[wind].size();j++)
                tree[alt].push_back(tree[wind][j]);
            tree[wind].erase(tree[wind].begin()+uindex, tree[wind].end());
        }
    }
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