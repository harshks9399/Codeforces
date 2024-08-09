// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int gcd(int a, int b){
    if(b==0) return a;
    a = a%b; //  in any case a < b
    return gcd(b, a);
}

bool check(vector<int>a, int index){
    if(index < 0 || index >= a.size()) return false;

    a.erase(a.begin() + index);

    vector<int>b(a.size()-1);
    for(int i=0;i<b.size();i++){
        b[i] = gcd(a[i], a[i+1]);
    }
    vector<int>check = b;
    sort(check.begin(), check.end());
    for(int i=0;i<b.size();i++) if(b[i] != check[i]) return false;
    // cout<<"index = "<<index<<"\n";
    // for()
    return true;
}


void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int>b(n-1);
    for(int i=0;i<n-1;i++)
        b[i] = gcd(a[i], a[i+1]);

    int index = -1;
    bool good = true;

    for(int i=0;i<n-2;i++){
        if(b[i] > b[i+1]) {
            if(index==-1){ index=i; break;}
            else{
                cout<<"NO\n";
                return;
            }
        }
    }
    // for(int it:b) cout<<it<<" ";
    // cout<<"\n";

    if(index==-1){  
        cout<<"YES\n";
            return;
    }
    if(check(a,index) || check(a,index+1) || check(a,index+2)) cout<<"YES\n";
    else cout<<"NO\n";
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