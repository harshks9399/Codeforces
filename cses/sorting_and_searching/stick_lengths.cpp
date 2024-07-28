// // THE BASIC SNIPPET
// #include <bits/stdc++.h>
// using namespace std;
// #define lli long long int

// void solve(){
//     int n;cin>>n;
//     vector<int>v;
//     int sum = 0;
//     while(n--){
//         int x;cin>>x;
//         v.push_back(x);
//         sum += x;
//     }
//     n = v.size();

//     sort(v.begin(), v.end());

//     int a = sum/n; 
//     int b = a+1;
//     int c = v[(n+1)/2];
//     lli ans1 =0, ans2= 0, ans3=0;
//     for(int it:v){
//         ans1 += abs(it-a);
//         ans2 += abs(it-b);
//         ans3 += abs(it-c);
//     }
//     ans1 =  (ans1 < ans2 ? ans1 : ans2);
//     ans3 = (ans1 < ans3 ? ans1: ans3);
//     cout<<ans3<<"\n";
//     return;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//         solve();
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N, p[maxN];
ll median, sum;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &p[i]);
    sort(p, p+N);

    median = p[(N-1)/2];
    for(int i = 0; i < N; i++)
        sum += abs(p[i]-median);
    printf("%lld\n", sum);
}