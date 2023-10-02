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

bool fits_in(pii a, pii b) {
    return (a.first < b.first) && (a.second < b.second);
}

int main() {
    fastio;

    int n;
    pii card;
    cin >> n >> card.first >> card.second;

    vector<pii> layers(1, card);
    map<pii, int> envelope_id;

    for(int i = 1; i <= n; i++) {
        pii envelope;
        cin >> envelope.first >> envelope.second;
        envelope_id[envelope] = i;
        if(fits_in(card, envelope)) {
            layers.push_back(envelope);
        }
    }

    sort(layers.begin(), layers.end());

    vector<int> dp(layers.size(), 0), last(layers.size(), -1);

    for(int i = 0; i < layers.size(); i++) {
        for(int j = 0; j < layers.size(); j++) {
            if(fits_in(layers[i], layers[j]) && dp[i]+1 > dp[j]) {
                dp[j] = dp[i]+1;
                last[j] = i;
            }
        }
    }

    auto it = max_element(dp.begin(), dp.end());
    cout << *it << '\n';

    vector<int> ans;
    for(int i = it - dp.begin(); i != 0; i = last[i]) {
        ans.push_back(envelope_id[layers[i]]);
    }

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i != ans.size()-1 ? ' ' : '\n');
    }
}