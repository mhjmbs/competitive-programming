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
    vector<int> sa, c, pos, lcp;

    SuffixArray(T s) : n(s.size()+1), sa(n), c(n), pos(n), lcp(n-1) {
        s.push_back(numeric_limits<typename T::value_type>::min());

        iota(sa.begin(), sa.end(), 0);
        copy(s.begin(), s.end(), c.begin());
        normalize(s);
        counting_sort();

        for(int k = 0; (1<<k) < n; k++) {
            for(int i = 0; i < n; i++) sa[i] = (sa[i]-(1<<k) + n) % n;
            counting_sort();

            vector<int> nc(n);
            for(int i = 1; i < n; i++) {
                nc[sa[i]] = nc[sa[i-1]] + (c[sa[i-1]] != c[sa[i]] || c[(sa[i-1] + (1<<k)) % n] != c[(sa[i] + (1<<k)) % n]);
            }
            
            swap(c, nc);
        }

        for(int i = 0; i < n; i++) pos[sa[i]] = i;

        kasai(s);
    }

    void normalize(T s) {
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) v[i] = {s[i], i};
        sort(v.begin(), v.end());
        c[v[0].second] = 0;
        for(int i = 1; i < n; i++) c[v[i].second] = c[v[i-1].second] + (v[i-1].first != v[i].first);
    }

    void counting_sort() {
        vector<int> nsa(n), cnt(n);
        for(int ci : c) cnt[ci]++;
        for(int i = 1; i < n; i++) cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--) nsa[--cnt[c[sa[i]]]] = sa[i];
        swap(nsa, sa);
    }

    void kasai(T s) {
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(pos[i] == n-1) continue;
            int j = sa[pos[i]+1];
            while(i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
            lcp[pos[i]] = k;
            k = max(0, k-1);
        }
    }
};

int main() {
    fastio;

    string s;
    cin >> s;

    int n = s.size();

    SuffixArray sa(s);

    ll ans = 0;;

    for(int i = 1; i < n; i++) {
        ans += (n - sa.sa[i]) - sa.lcp[i];
    }
    ans += n-sa.sa[n];

    cout << ans << '\n';
}