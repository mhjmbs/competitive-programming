#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for(int & xi : x) cin >> xi;

    int start = 0, end = 0;

    ordered_multiset window;
    map<int,int> occur;

    while(end < k) {
        window.insert(x[end]);
        occur[x[end]]++;
        end++;
    }

    int last_median = 0;
    vector<ll> ans(n-k+1);

    last_median = *window.find_by_order((k-1)/2);
    for(ll num : window) ans[0] += abs(last_median - num);
    int i = 1;

    while(true) {
        if(i == n-k+1) break;
        ans[i] = ans[i-1];

        ans[i] -= abs(last_median - x[start]);
        window.erase(window.upper_bound(x[start]));
        occur[x[start]]--;
        start++;

        ans[i] += abs(last_median - x[end]);
        window.insert(x[end]);
        occur[x[end]]++;
        end++;

        int curr_median = *window.find_by_order((k-1)/2);
        int diff = curr_median - last_median;

        //variação de caras estritamente menores que ambas as medianas
        ans[i] += min(window.order_of_key(curr_median), window.order_of_key(last_median)) * diff;

        //variação de caras estritamente maiores que ambas as medianas
        auto it = window.lower_bound(max(curr_median, last_median));
        if(it != window.end()) {
            ans[i] -= (window.size() - window.order_of_key(*it)) * diff;
        }

        //variação de caras entre as duas medianas
        ans[i] += occur[last_median] * abs(curr_median - last_median);
        ans[i] -= occur[curr_median] * abs(curr_median - last_median);

        i++;

        last_median = curr_median;
    }

    for(int i = 0; i < n-k+1; i++) {
        cout << ans[i];
        if(i != n-k) cout << ' ';
        else cout << '\n';
    }
}