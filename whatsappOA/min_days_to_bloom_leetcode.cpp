#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;
//Given an array of roses. roses[i] means rose i will bloom on day roses[i]
//Also given an int k, which is the minimum number of adjacent bloom roses required for a bouquet, 
//and an int n, which is the number of bouquets we need
//Return the earliest day that we can get n bouquets of roses.


int min_days_to_bloom(vector<int>roses, int k, int n){
    // solution exists?
    if(roses.size()/k < n) return 0; 

    int lh = *min_element(roses.begin(), roses.end());
    int rh = *max_element(roses.begin(), roses.end());
    ans = rh;
    while(lh <= rh){
        int mh = lh + (rh-lh)/2;
        int running = 0;
        int curr =0;
        for(int it: roses ){
            if(it <= mh) running++;
            else running = 0;
            if(running >= k) {
                curr++;
                running = 0;
            }
        }
        if(curr >= n){
            ans = mh;
            rh = mh-1;
        }else lh = mh+1;
    }
    return ans;
}


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<solve(n,m,k)<<"\n";
    return 0;
}