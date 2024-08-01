
    // THE BASIC SNIPPET
    #include <bits/stdc++.h>
    using namespace std;
    #define lli long long int
     
    void solve(){
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        vector<vector<int>>river(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int x;cin>>x;
                river[i][j] = x;
            }
        
        vector<int>score(n,-1);
        for(int i=0;i<n;i++){
            vector<lli>dp(m,0);
            dp[0]=1;
            multiset<lli>cost;
            cost.insert(1);
            for(int j=1;j<m;j++){
                int flag =( j-d-1);
                int low_lim = max(flag,0);
                dp[j] = river[i][j] + *cost.begin() + 1;
                if(flag >= 0) cost.erase(cost.find(dp[flag]));
                cost.insert(dp[j]);
            }
            score[i] = dp[m-1];
        }
        lli sum =0;
        lli ans = 0;
        for(int i=0;i<k;i++) sum += score[i];
        ans = sum;
        for(int i=k;i<n;i++){
            sum = sum + score[i] - score[i-k];
            ans = ans < sum ? ans : sum;
        }
        cout<<ans<<"\n";
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