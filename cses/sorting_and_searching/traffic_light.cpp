// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n,q;
    cin>>n>>q;
    multiset<int>v,dist;
    v.insert(0);
    v.insert(n);
    dist.insert(n);

    while(q--){
        
        int x;
        cin>>x;

        auto it1 = v.upper_bound(x);
        auto it2 = it1--;
        
        int old_dist = (*it2) - (*it1) ;
        int nd1 = (*it2) - x ;
        int nd2 = x - (*it1) ;
        dist.erase(dist.find(old_dist));
        dist.insert(nd1);
        dist.insert(nd2);
        v.insert(x);
        auto ans = dist.end();
        ans--;
        cout<<*ans<<" ";
        
    }
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	int street_len;
// 	int light_num;
// 	cin >> street_len >> light_num;

// 	set<int> lights{0, street_len};
// 	multiset<int> dist{street_len};
// 	for (int l = 0; l < light_num; l++) {
// 		int pos;
// 		cin >> pos;

// 		auto it1 = lights.upper_bound(pos);
// 		auto it2 = it1;
// 		--it2;

// 		dist.erase(dist.find(*it1 - *it2));
// 		dist.insert(pos - *it2);
// 		dist.insert(*it1 - pos);
// 		lights.insert(pos);

// 		auto ans = dist.end();
// 		--ans;
// 		cout << *ans << " ";
// 	}
// }