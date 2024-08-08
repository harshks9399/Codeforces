// THE BASIC SNIPPET
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    sort(v.begin(), v.end());
    lli ans = 0;
    int i = 0;
    while(i<n){
        lli count  = 0;
        int j = i+1;
        for( ;j<n;j++){
            bool good  = true;
            int mini = v[i];
            int maxi = v[j];
            while(mini!=0 && maxi!=0){
                if(mini==1 && maxi==1) {count++; break;}
                mini = mini >> 1;
                maxi = maxi >> 1;
                if(mini==0 || maxi==0){
                    good  = false;
                    break;
                }
            }
            if(!good) break;
        }
        i =j;
        count++;
        // cout<<"count = "<<count<<"\n";
        ans += (count * (count-1))/2;
    }
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