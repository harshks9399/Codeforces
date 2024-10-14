/*
 Author : Harsh Kumar Singh
 created at : 2024-10-11 15:34:33
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
// int fun(){
//     return 1;
// }

// int fun(int x){
//     return x;
// }

void fun(float x){
    cout<<x<<"\n";
}

struct node{

    int x;
    node(int a) : x(a) {}
};


void solve(){
    fun(1.2);
    node * a = new node(2);
    node * b = new node(3);
    if(a == b) cout<<"same\n";
    else cout<<"not same\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}