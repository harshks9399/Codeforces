// THE BASIC SNIPPET
// We have template for fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
bool fun_sort(pair<int,int>a, pair<int,int>b){
    if(a.first!= b.first) return a.first < b.first;
    else return a.second > b.second;
}

class fenwick_tree{
    int n_;
    vector<int>v;

    public :
    fenwick_tree(int n){
        n_ = n;
        v = vector<int>(n+1,0);
    }

    void update (int index, int add){ // adding sum to the given index and the other indices as needed
        // v[index] += add;
        for(;index<=n_;  index = index + (index & (-1 * index)))
            v[index] += add;

        // i = i + (i * -i)
    }   

    int sum_1(int index){
        int ans = 0;
        for(; index >=1 ; index = index - (index & (-1 * index)))
            ans += v[index];
        return ans;
    }
    
    int sum_2(int left, int right){ // right inclusive , left exclusive
    if(left == 0) return sum_1(right);
        int ans = sum_1(right) -  sum_1(left);
        return ans;
    }

};


void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    while(n--){
        int x,y;cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end(), fun_sort);

    fenwick_tree ft(v.size());


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}