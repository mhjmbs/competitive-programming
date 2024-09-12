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

    int n;
    cin >> n;

    vector<int> w(n);
    for(int& wi : w) cin >> wi;

    reverse(w.begin(), w.end());

    vector<int> w2;
    w2.reserve(n);

    int okCount = 0;
    vector<int> ans;
    ans.reserve(2*n);

    while(okCount < n) {
        if(w.size() - okCount > 0) ans.push_back(w.size() - okCount);
        w2.insert(w2.end(), w.begin()+okCount, w.end());
        w.erase(w.begin()+okCount, w.end());

        auto it = max_element(w2.begin(), w2.end());

        ans.push_back(-(w2.size() - (it-w2.begin())));
        w.insert(w.end(), it, w2.end());
        w2.erase(it, w2.end());
        okCount++;
    }

    cout << ans.size() << '\n';
    for(int x : ans) cout << x << '\n';
}