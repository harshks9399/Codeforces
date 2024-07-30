// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool fun_comp(pair<int,int>a, pair<int,int>b){
    if(a.first!= b.first) return a.first < b.first;
    else return a.second  > b.second;
}

void solve(){
    int n;cin>>n;
    map<pair<int,int>,int>pos;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v[i] = {x,y};
        pos[v[i]] = i;
    }

    sort(v.begin(), v.end(), fun_comp);

    int ans = 1;
    int curr = 0;
    int t_now = -1;
    map<pair<int,int>,int>rooms;
    set<pair<int,int>>time;
    unordered_set<int>rooms_lst;
    rooms_lst.insert(1);
    
    for(auto it:v){
        int s = it.first, e = it.second;
        if(curr==0 || time.empty()){
            time.clear();
            time.insert(it);
            curr++;
            rooms[it] = *rooms_lst.begin();
            rooms_lst.erase(rooms_lst.begin());
            continue;
        }

        t_now = s;
        while(t_now > (*time.begin()).second){
            curr--;
            rooms_lst.insert(rooms[*time.begin()]);
            time.erase(time.begin());
            if(time.empty()) break;
        }

        time.insert(it);
        curr++;

        if(ans < curr){
            rooms_lst.insert(curr);
            ans = curr;
        }
        rooms[it] = *rooms_lst.begin();
        rooms_lst.erase(rooms_lst.begin());
    }

    cout<<ans<<"\n";
    for(auto it:v)
        cout<<rooms[it]<<" ";
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}