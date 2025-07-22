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

template <typename T>
vector<T> sieve(int n) {
    vector<T> is_p(n+1, true);
    is_p[0] = is_p[1] = false;
    
    for(T i = 2; i*i <= n; i++) {
        if(is_p[i]) {
            for(T j = i*i; j <= n; j+=i) {
                is_p[j] = false;
            }
        }
    }

    return is_p;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> is_p = sieve<int>(n);
        cout << count(is_p.begin(), is_p.end(), true) << '\n';
    }
}