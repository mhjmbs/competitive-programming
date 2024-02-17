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

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        map<ll,int> occur;
        for(int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            a[i] = ai + i+1;
            occur[a[i]]++;
        }
    
        set<ll> S;

        while(!occur.empty()) {
            auto it = occur.end();
            it--;
            auto [curr, freq] = *it;
            occur.erase(it);

            S.insert(curr);
            freq--;

            if(freq > 0) occur[curr-1] += freq;
        }

        for(auto it = S.rbegin(); it != S.rend(); it++) {
            cout << *it << ' ';
        }
        cout << '\n';
    }
}