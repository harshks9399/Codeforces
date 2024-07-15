// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli effort_calc(vector<int>&step){
    int n = step.size();
    if(n%2==0){
        lli sum = 0;
        for(int it:step)
            sum += it;
        return 2*sum;
    }
    else{
        int maxi = -1;
        int pos = -1;
        for(int i=0;i<n;i++){
            if(i%2==1) continue;
            if(maxi < step[i]){
                maxi = step[i];
                pos = i;
            }
        }
        lli sum = 0;
        for(int i=0;i<n;i++){
            if(i==pos) continue;
            sum += step[i];
        }
        sum = 2*sum + step[pos];
        return sum;
    }
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vector<lli>a(n+2);
    a[0]=0;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    a[n+1]=0;

    int index  = 0;
    vector<int>step;
    lli total_effort = 0;
    while(index<a.size()){
        if(a[index]==0){
            if(step.size()!=0)
                total_effort += effort_calc(step);
            step.clear();
        }else{
            step.push_back(a[index]);
        }
        index++;
    }
    cout<<total_effort<<"\n";
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