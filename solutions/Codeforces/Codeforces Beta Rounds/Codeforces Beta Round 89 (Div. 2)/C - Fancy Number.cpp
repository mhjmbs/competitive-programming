#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k;
string s;
vector<int> occur(10, 0);
int ans = INT_MAX;
string new_s;

bool smaller(const string &a, const string& b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

void compute(int k, int d) {
    vector<int> diff_occur(10, 0);
    diff_occur[0] = occur[d];

    for(int i = 1; i <= 9; i++) {
        if(d+i <= 9) diff_occur[i] += occur[d+i];
        if(d-i >= 0) diff_occur[i] += occur[d-i];
    }

    int diff = 0;
    int curr_ans = 0;
    vector<int> diff_change(10, 0);

    while(k > 0) {
        int change = min(diff_occur[diff], k);
        diff_change[diff] += change;
        k -= change;
        curr_ans += change * diff;
        diff++;
    }

    string best = s;

    for(int diff = 1; diff <= 9; diff++) {
        if(d+diff <= 9) {
            for(int i = 0; i < n; i++) {
                if(best[i] - '0' == d+diff && diff_change[diff] > 0) {
                    best[i] = d + '0';
                    diff_change[diff]--;
                }
            }
        }
        if(d-diff >= 0) {
            for(int i = n-1; i >= 0; i--) {
                if(best[i] - '0' == d-diff && diff_change[diff] > 0) {
                    best[i] = d + '0';
                    diff_change[diff]--;
                }
            }
        }
    }

    if(curr_ans < ans || (curr_ans == ans && smaller(best, new_s))) {
        ans = curr_ans;
        new_s = best;
    }
}

int main() {
    fastio;

    cin >> n >> k;
    cin >> s;

    for(char c : s) occur[c - '0']++;

    for(int d = 0; d <= 9; d++) {
        compute(k, d);
    }

    cout << ans << '\n';
    cout << new_s << '\n';
}