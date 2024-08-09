// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool fun_sort(pair<int,int>p1,pair<int,int>p2){
    return min(p1.first, p1.second) >= min(p2.first, p2.second);
}

void solve(){
    int n;
    cin>>n;

    int s1=0, s2=0;
    vector<int>q1(n),q2(n);
    for(int i=0;i<n;i++) cin>>q1[i];
    for(int i=0;i<n;i++) cin>>q2[i];
    int neg = 0, pos = 0;

    for(int i=0;i<n;i++){
       if(q1[i]==q2[i] && q1[i]==1) {pos++;continue;}
       if(q1[i]==q2[i] && q2[i]==-1) {neg++;continue;}

        if(q1[i] > q2[i]) s1 += q1[i];
        else s2 += q2[i];
    } 

    while(pos > 0){
        if(s1 > s2) s2++;
        else s1++;
        pos--;
    }
    while(neg > 0){
        if(s1 > s2) s1--;
        else s2--;
        neg--;
    }
    cout<<min(s1,s2)<<"\n";

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