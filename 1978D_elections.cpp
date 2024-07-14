// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void solve(){
    int n,c;
    cin>>n>>c;
    vector<pair<lli,int>>v;
    map<int,lli>score;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i==1) x = x + c;
        v.push_back({x,-1*i});
        score[i]= x;
    }
    vector<lli>cum_score(n);
    cum_score[0] = v[0].first;
    for(int i =1;i<n;i++){
        cum_score[i] = cum_score[i-1] + v[i].first;
    }
    sort(v.begin(),v.end(), greater<pair<int,int>>());

    

    map<int,int>pos;
    for(int i=0;i<n;i++){
        pos[-1 * v[i].second] = i;
    }

    vector<int>sol;
    for(int i=1;i<=n;i++){
        lli curr_score = score[i];
        int top_Candidate = -1 * v[0].second;
        lli top_score = v[0].first;
        if(top_Candidate == i){
            sol.push_back(0);
            continue;
        }
        int rem = 0;
        curr_score = cum_score[i-1];
        rem = i-1;
        if(curr_score >= top_score){
            sol.push_back(rem);
        }
        else 
            sol.push_back(rem+1);
    }
    for(int it:sol){
        cout<<it<<" ";
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