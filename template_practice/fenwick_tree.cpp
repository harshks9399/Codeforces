// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

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


    void check(){

        for(int i = 1; i<=n_ ; i++) 
            cout<<v[i]<<" ";
        cout<<"\n";
    }

};

void solve(){
    vector<int>v = {2,1,1,3,2,3,4,5,6,7,8,9};
    fenwick_tree ft(v.size());
    for(int i=0;i<v.size();i++)
        ft.update(i+1, v[i]);
    ft.check();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}