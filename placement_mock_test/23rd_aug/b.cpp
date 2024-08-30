/*
 Author : Harsh Kumar Singh
 created at : 2024-08-23 21:10:14
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair

bool fun(pair<int,int>a, pair<int,int>b){
    // if(a.first!= b.first ) return a.first  < b.first;
    // else return a.second < b.second;

    // disjoint
    if(a.second < b.first ) return true;

    // partial
    if(a.first < b.first && a.second < b.second && a.second >= b.first) return true; 

    // completely inside
}


void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        v.push_back(mp(a,b));
    }
    sort(v.begin(), v.end(), fun);
    // vector<int>check(1e9+1,0);
    int last = 0;
    bool good =  true;
    for(auto it: v){
        int a = it.first, b = it.second;
        if(last < a) {
            // check[a] = 1;
            last = a;
            continue;
        }

        if(last < b){
            last++;
            // check[last] = 1;
            continue;;
        }

        good = false;
        break;

    }
    if(good) cout<<"YES\n";
    else cout<<"NO\n";
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