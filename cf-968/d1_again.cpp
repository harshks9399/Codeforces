/*
 Author : Harsh Kumar Singh
 created at : 2024-08-25 21:16:14
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli sumn(int x){
    lli ans = 0;
    lli temp = x;
    ans = temp * (temp+1);
    ans /= 2;
    return ans;
}


int mex(vector<int>& arr, int N)
{
    // Create a map to store the frequency of each element
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[arr[i]]++;
    }
 
    // Initialize MEX to 0
    int mex = 0;
 
    // Iterate through non-negative integers from 0 to N
    for (int i = 0; i <= N; i++) {
        // Find the first integer with a frequency of 0 in the map
        if (mp[i] == 0) {
            mex = i;
            break;
        }
    }
 
    // Return MEX as the answer
    return mex;
}


void solve(){
    int n,m;
    cin>>n>>m;
    // vector<pair<int,int>>check;
    // multiset<int>start;
    // map<int,int>score;
    int def_max = -1;
    while(n--){
        int li ;
        int maxi = -1;
        cin>>li;
        vector<int>temp(li);
        for(int &it : temp) cin>>it;
        int a = mex(temp, li);
        temp.push_back(a);
        int b = mex(temp, li+1);
        def_max = max(b, def_max);
    }
    lli ans = 0;
    // for(int i=0;i<=m;i++){
    //     if(i < def_max) ans += def_max;
    //     else ans += i;
    // }
    lli df = def_max;
    if(m >= def_max){
        ans += df*(df+1);
        //ans += (m-df)*m;
        ans += sumn(m);
        ans -= sumn(def_max);
    }
    else ans += (m+1)*df;
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