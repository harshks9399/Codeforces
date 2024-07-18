// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,t;
    cin>>n>>t;
    vector<int>dir;
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        if(x=='1') dir.push_back(1);
        else  dir.push_back(-1);
    }
    vector<lli>left,right;
    for(int i=0;i<n;i++){
        int xx;
        cin>>xx;
        if(dir[i]==1) right.push_back(xx);
        else left.push_back(xx);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    if(left.size()==0 || right.size()==0){
        cout<<"0";
        return;
    }
    left.push_back(1e9 + 2);
    int i=0,j=0;
    lli ans  =0 ;
    for(int it:right){
        int i_dis = left[i]-it;
        int j_dis = left[j]-it;
        while(left[i] < it){
            if(i>=left.size()-1)
                break;
            i++;
            i_dis = left[i]-it;
        }
        while(j_dis <= 2*t + 0.2){
            if(j>=left.size()-1)
                break;
            j++;
            j_dis = left[j]-it;
        }
        if(i_dis > 2*t + 0.2){
            i++;
            continue;
        }
        ans += j-i;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t=1;
    while(t--)
        solve();
    return 0;
}