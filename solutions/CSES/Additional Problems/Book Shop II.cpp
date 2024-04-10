#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;
 
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
int main() {
    fastio;
 
    int n, x;
    cin >> n >> x;
 
    vector<int> h(n), s(n), k(n);
    
    for(int& hi : h) cin >> hi;
    for(int& si : s) cin >> si;
    for(int& ki : k) cin >> ki;
    
    vector<int> dp(x+1, 0);
 
    for(int i = 0; i < n; i++) {
        int pow = 1;
        while(k[i] > 0) {
            if(pow > k[i]) pow = 1;
            for(int j = x; j-h[i]*pow >= 0; j--) {
                dp[j] = max(dp[j], dp[j-h[i]*pow]+s[i]*pow);
            }
            k[i] -= pow;
            pow *= 2;
        }
    }
 
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}