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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int sum = accumulate(a.begin(), a.end(), 0);

    if(sum % 2 != 0) {
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int s1 = sum/2; s1 >= 0; s1--) {
            if(s1-a[i] >= 0 && dp[i-1][s1-a[i]]) {
                dp[i][s1] = 1;
            }else if(dp[i-1][s1]) {
                dp[i][s1] = 2;
            }
        }
    }

    if(!dp[n][sum/2]) {
        cout << -1 << '\n';
        return 0;
    }
    
    vector<int> alice, bob;

    for(int i = n, curr = sum/2; i > 0; i--) {
        if(dp[i][curr] == 1) {
            alice.push_back(a[i]);
            curr -= a[i];
        }else {
            bob.push_back(a[i]);
        }
    }

    int s1 = 0, s2 = 0;

    for(int i = 0; i < n; i++) {
        if(s1 <= s2) {
            cout << alice.back() << ' ';
            s1 += alice.back();
            alice.pop_back();
        }else {
            cout << bob.back() << ' ';
            s2 += bob.back();
            bob.pop_back();
        }
    }
    cout << '\n';
}