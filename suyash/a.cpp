// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

#define lli  long long int

vector<lli>dp_c(51,-1); // number of c in nth string
lli str_len_fun(int n){
    if(n == 1)
        return 1;
    else
        {
            lli ans = 0;
            n--;
            // ans = 3(2^n - 1) + 2^n;
            ans = 3*(pow(2,n) - 1) + pow(2,n);
            return ans;
        }
}

lli find_c(int index){
    if(dp_c[index]==-1){
        if(index%2==1){
            return dp_c[index] = 2*find_c(index-1) + 2;
        }else
            return dp_c[index] = 2*find_c(index-1) + 1;
        
    }
    else return dp_c[index];
}

int solve(int n,int k){
    if(dp_c[n]==-1) find_c(n);
    if(k<=0) return 0;
    if(n==1)
    {
        if(k>=1) return 1;
        else return 0;
    }
    lli str_len = str_len_fun(n);
    lli count_c =dp_c[n];
    
    // cout<<"str_len="<<str_len<<"\n";
    // cout<<"count_c="<<count_c<<"\n";
    
    
    if(k >= str_len) return dp_c[n];
    
    if(k > (str_len/2)){
        int mid = n%2 ? 0:1;
        int start  = n%2 ? 1:0;
        k = k - (str_len/2) - 1;
        lli ans =  start + dp_c[n-1] + mid + solve(n-1,k);
        
        return ans;
    }
    else{
        int start  = n%2 ? 1:0;
        lli ans = start + solve(n-1,k-1);
        return ans;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    dp_c[0]=0;
    dp_c[1]=1;
    cin>>n>>k;
    cout<<solve(n,k);
    
}