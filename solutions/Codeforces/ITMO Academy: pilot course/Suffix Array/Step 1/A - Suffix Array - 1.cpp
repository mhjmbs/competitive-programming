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

struct SuffixArray {
    int n;
    vector<int> sa, c;

    SuffixArray(string s) : n(s.size()+1), sa(n), c(n) {
        s += '$';

        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&s](int i, int j) {return s[i] < s[j];});
        for(int i = 0; i < n; i++) {
            c[i] = (s[i] >= 'a') ? s[i]-'a'+1 : 0;
        }

        for(int k = 0; (1<<k) < n; k++) {
            vector<int> nc(n);
            
            sort(sa.begin(), sa.end(), [k, this](int i, int j) {
                if(c[i] != c[j]) return c[i] < c[j];
                return c[(i+(1<<k))%n] < c[(j+(1<<k))%n];
            });
            
            for(int i = 1; i < n; i++) {
                nc[sa[i]] = nc[sa[i-1]];
                if(c[sa[i]] != c[sa[i-1]]) nc[sa[i]]++;
                else if(c[(sa[i]+(1<<k))%n] != c[(sa[i-1]+(1<<k))%n]) nc[sa[i]]++;
            }

            swap(c,nc);
        }
    }
};

int main() {
    fastio;

    string s;
    cin >> s;

    SuffixArray sa(s);

    for(int i = 0; i < sa.sa.size(); i++) {
        cout << sa.sa[i] << ' ';
    }
    cout << '\n';
}