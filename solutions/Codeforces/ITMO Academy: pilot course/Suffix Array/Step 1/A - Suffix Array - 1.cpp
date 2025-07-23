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
struct SuffixArray {
    int n;
    vector<int> sa, c;

    SuffixArray(T s) : n(s.size()+1), sa(n), c(n) {
        s.push_back(numeric_limits<typename T::value_type>::min());

        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        copy(s.begin(), s.end(), c.begin());

        for(int k = 0; (1<<k) < n; k++) {
            sort(sa.begin(), sa.end(), [this, k](int i, int j) {
                if(c[i] != c[j]) return c[i] < c[j];
                return c[(i+(1<<k)) % n] < c[(j+(1<<k)) % n];
            });

            vector<int> nc(n);
            for(int i = 1; i < n; i++) {
                nc[sa[i]] = nc[sa[i-1]] + (c[sa[i-1]] != c[sa[i]] || c[(sa[i-1] + (1<<k)) % n] != c[(sa[i] + (1<<k)) % n]);
            }
            
            swap(c, nc);
        }
    }
};

int main() {
    fastio;

    string s;
    cin >> s;

    SuffixArray sa(s);

    for(int i : sa.sa) {
        cout << i << ' ';
    }
    cout << '\n';
}