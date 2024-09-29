/*
 Author : Harsh Kumar Singh
 created at : 2024-08-19 21:30:56
*/
//TEMPLATES : ft, expo, gcd, seive
#include <bits/stdc++.h>
using namespace std;
#define lli long long int


struct vertex{
    vector<vertex*>child;
    bool end;
    vertex(){
        end = false;
        for(int i=0;i<26;i++) child.push_back(nullptr);
    }
};

void insert(vertex * node, string s,  int n){
    int v = s[n] - 'a';
    if(n==s.size()-1){
        if(node->child[v]==NULL) node->child[v] = new vertex();
        node->child[v]->end = true;
        return;
    }
    if(node->child[v]==NULL) node->child[v] = new vertex();
    insert(node->child[v], s, n+1);
}

bool find(vertex * node, string s, int n){
    int v = s[n] - 'a';
    if(n==s.size()-1){
        if(node->child[v]==NULL) return false;
        return node->child[v]->end;
    }

    if(node->child[v]==NULL) return false;
    return find(node->child[v], s, n+1);
}





void solve(){
    int n,q;
    cin>>n>>q;
    vector<string>ip;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ip.push_back(s);
    }

    vertex * trie = new vertex();
    for(string s: ip) insert(trie, s, 0);

    while(q--){
        string s;
        cin>>s;
        if(find(trie, s, 0))cout<<"the string "<<s<<" found in trie\n";
        else cout<<"string doesnt found\n";
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}