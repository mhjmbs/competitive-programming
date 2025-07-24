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
    vector<int> sa;

    SuffixArray(T s) : n(s.size()+1), sa(n){
        s.push_back(numeric_limits<typename T::value_type>::min());
        vector<int> c(n);

        iota(sa.begin(), sa.end(), 0);
        copy(s.begin(), s.end(), c.begin());
        normalize(s,c);
        counting_sort(c);

        for(int k = 0; (1<<k) < n; k++) {
            for(int i = 0; i < n; i++) sa[i] = (sa[i]-(1<<k) + n) % n;
            counting_sort(c);

            vector<int> nc(n);
            for(int i = 1; i < n; i++) {
                nc[sa[i]] = nc[sa[i-1]] + (c[sa[i-1]] != c[sa[i]] || c[(sa[i-1] + (1<<k)) % n] != c[(sa[i] + (1<<k)) % n]);
            }
            
            swap(c, nc);
        }
    }

    void normalize(string& s, vector<int>& c) {
        vector<pair<typename T::value_type, int>> bla(n);
        for(int i = 0; i < n; i++) bla[i] = {s[i], i};
        sort(bla.begin(), bla.end());
        c[bla[0].second] = 0;
        for(int i = 1; i < n; i++) c[bla[i].second] = c[bla[i-1].second] + (bla[i-1].first != bla[i].first);
    }

    void counting_sort(vector<int>& c) {
        vector<int> nsa(n), cnt(n);
        for(int ci : c) cnt[ci]++;
        for(int i = 1; i < n; i++) cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--) nsa[--cnt[c[sa[i]]]] = sa[i];
        swap(nsa, sa);
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