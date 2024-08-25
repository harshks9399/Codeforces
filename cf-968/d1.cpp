/*
 Author : Harsh Kumar Singh
 created at : 2024-08-25 20:45:52
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

// const int N = 1e9 + 1;
// vector<int>maxi(N,-1);

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>check;
    multiset<int>start;
    map<int,int>score;

    while(n--){
        int li ;
        int maxi = -1;
        cin>>li;
        multiset<int>curr;
        while(li--){
            int x;
            cin>>x;
            curr.insert(x);
            maxi = max(x, maxi);
        }
        int a = -1, b= -1;
        for(int i=0;i<=maxi+1;i++){
            if(curr.find(i)!=curr.end()) continue;
            a = i;
            break;
        }

        for(int i=a+1;i<=maxi+2;i++){
            if(curr.find(i)!=curr.end()) continue;
            b = i;
            break;
        }
        check.push_back(make_pair(a,b));
        if(start.find(a)==start.end()) start.insert(a);
        // score[a] = max(score[b])
    }
    vector<pair<int,int>>check_rev;
    for(auto it: check){
        int  a = it.first, b= it.second;
        check_rev.push_back(make_pair(b,a));
    }
    sort(check_rev.begin(), check_rev.end(), greater<pair<int,int>>());
    for(auto it: check_rev){
        int  a = it.first, b= it.second;
        // a > b
        score[b] = max(score[b], a);
        score[b] = max(score[b], score[a]);
    }
    int def_max = -1;
    for(int it: start){
        def_max = max(def_max, score[it]);
    }

    lli ans = 0;
    for(int i=0;i<=m;i++){
        // auto itr = start.lower_bound(i);
        // if(itr==start.end())
        if(i < def_max) ans += def_max;
        else ans += i;
    }
    cout<<ans<<"\n";




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