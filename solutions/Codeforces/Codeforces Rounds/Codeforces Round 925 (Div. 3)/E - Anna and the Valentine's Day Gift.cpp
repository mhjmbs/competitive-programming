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

int digitCount(int x) {
    int ans = 0;
    while(x > 0) {
        ans++;
        x /= 10;
    }
    return ans;
}

int zeroCount(int x) {
    int ans = 0;
    while(x > 0) {
        if(x % 10 == 0) {
            ans++;
            x /= 10;
        }else {
            break;
        }
    }
    return ans;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        multiset<pii> numbers;

        for(int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            numbers.emplace(zeroCount(ai), digitCount(ai));
        }

        while(true) {
            pii best = *numbers.rbegin();
            numbers.erase(numbers.lower_bound(best));
            best.second -= best.first;
            best.first = 0;
            numbers.insert(best);

            if(numbers.size() == 1) break;
        
            best = *numbers.rbegin();
            pii worst = *numbers.begin();
            numbers.erase(numbers.lower_bound(best));
            numbers.erase(numbers.lower_bound(worst));

            best = {worst.first, best.second + worst.second};
            numbers.insert(best);
        }

        if(numbers.begin()->second > m) cout << "Sasha\n";
        else cout << "Anna\n";
    }
}