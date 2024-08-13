// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    char C;
    cin>>C;

    map<char,multiset<int>>m;
    for(int i =0;i<2*n;i++){
        char a,b;
        // string temp = "";
        cin>>a>>b;
        // temp += a;
        // int b_num = stoi(temp);
        int b_num = int(a - '0');
        m[b].insert(b_num);
    }
    vector<pair<int,char>>A,B;
    vector<char> suits = {'H', 'S', 'C', 'D'};

    // for(auto it:m){
    //     for(int i:it.second) cout<<it.first<<" "<<i<<"\n";
    // }
    // cout<<"C = "<<C<<"\n";


    for(char c:suits){
        if(c==C || m[c].size()==0) continue;

        while(1){
            if(m[c].size()==1 && m[C].size()==0){
                cout<<"IMPOSSIBLE\n";
                return;
            }

            if(m[c].size()==1){
                A.push_back({*(m[c].begin()), c});
                B.push_back({*(m[C].begin()), C});
                m[c].erase(m[c].begin());
                m[C].erase(m[C].begin());
            }else{
                A.push_back({*(m[c].begin()), c});
                B.push_back({*(m[c].rbegin()), c});
                m[c].erase(m[c].begin());
                // m[c].erase(m[c].rbegin());
                m[c].erase(prev(m[c].end()));
            }
            if(m[c].size()==0) break;
        }
    }
    if(m[C].size()%2==1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    while (m[C].size()!=0) {
        A.push_back({*(m[C].begin()), C});
        B.push_back({*(m[C].rbegin()), C});
        m[C].erase(m[C].begin());
        // m[C].erase(m[C].rbegin());
        m[C].erase(prev(m[C].end()));
    }

    for(int i=0;i<n;i++){
        cout<<A[i].first<<A[i].second<<" "<<B[i].first<<B[i].second<<"\n";
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

    // char x = '2';
    // string temp ="";
    // temp += x;
    // int a = stoi(temp);
    // cout<<a+19<<"\n";

    return 0;
}