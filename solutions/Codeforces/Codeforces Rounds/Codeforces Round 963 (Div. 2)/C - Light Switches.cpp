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

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<pii> a(n);
        int minAns = -1, minAnsMod = -1;
        for(pii& ai : a) {
            cin >> ai.first;
            ai.first--;
            ai.second = ai.first;
            ai.first %= 2*k;
            if(ai.second > minAns) {
                minAnsMod = ai.first;
                minAns = ai.second;
            }
        }

        sort(a.begin(), a.end());

        int on = 0;

        priority_queue<pii, vector<pii>, greater<pii>> prioq;
        for(auto [am, ai] : a) {
            if(am >= k && ai < minAns-minAnsMod) {
                on++;
                prioq.emplace((am+k)%(2*k),0);
            }else {
                prioq.emplace(am, 1);
            }
        };

        int ans = -1;

        while(!prioq.empty()) {
            auto [pos, event] = prioq.top();
            prioq.pop();

            if(event == 1) {
                on++;
                if(pos+k < 4*k) prioq.emplace(pos+k, 0);
            }else {
                on--;
                if(pos+k < 4*k) prioq.emplace(pos+k, 1);
            }

            if(on == n) {
                ans = minAns + pos-minAnsMod;
                break;
            }

        }

        if(ans == -1) cout << ans << '\n';
        else cout << ans+1 << '\n';
    }
}