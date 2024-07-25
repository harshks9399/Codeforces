// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        if(n==1) return s;
        if(n==2){
            if(s[0]==s[1]) return s;
            else return ans = s[0];
        } 
        // if(n==3){
        //     ans = "";
        //     unordered_set<char>check3;
        //     for(char ss:s) check3.insert(ss);
        //     if(check3.size()==3) return ans =  s[0];
        //     if(check3.size()==2){
        //         if(s[0]==s[1]) return ans = s[0] + s[1];
        //         if(s[2]==s[1]) return ans = s[2] + s[2] ;
        //         if(s[0]==s[2]) return s;
        //     }
        //     else return s;
        // }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) dp[i][i+1]=1;
        // for(int i=0;i<n-2;i++) if(s[i]==s[i+2]) dp[i][i+2]=1;

        for(int k=3;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j = i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1) dp[i][j]=1;
            }
        }
        int ans_i=0, ans_j=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(dp[i][j]!=1) continue;
                if(  ans_j-ans_i < j-i  ){
                    ans_j = j;
                    ans_i = i;
                }
            }
        
        for(int i=ans_i;i<=ans_j;i++)
            ans += s[i];
        return ans;
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<"\n";
    return 0;
}