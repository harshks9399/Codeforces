/*
 Author : Harsh Kumar Singh
 created at : 2024-08-30 20:14:29
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,m;
    cin>>n>>m;
    vector<lli>v(n);
    for(lli &it : v) cin>>it;
    multiset<int>add,sub;
    while(m--){
        char c;
        cin>>c;
        int l, r;
        cin>>l>>r;
        if(c=='+'){
            add.insert(r);
            if(l!=1) sub.insert(l-1);
        }
        else{
            sub.insert(r);
            if(l!=1) add.insert(l-1);
        }
    }

    lli maxi = LLONG_MIN/10;
    for(lli temp: v){
        //add:
        lli it = temp;
        auto add_iter = add.lower_bound(it);
        if(add_iter!=add.end()){
            lli amt = distance(add_iter, add.end());
            it += amt;
        }

        //sub
        auto sub_iter = sub.lower_bound(temp);
        if(sub_iter!=sub.end()){
            lli amt = distance(sub_iter, sub.end());
            it -= amt;
        }
        maxi = maxi > it ? maxi : it;
        cout<<maxi<<" ";
    }
    cout<<"\n";
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