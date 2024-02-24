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

set<int> oddOccurPrimes(int n) {
    map<int,int> primes;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            primes[d]++;
            n /= d;
        }
    }

    if (n > 1) primes[n]++;

    set<int> ans;
    for(auto [prime, occur] : primes) {
        if(occur % 2 == 1) ans.insert(prime);
    }

    return ans;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    map<set<int>, int> wow;
    ll ans = 0, zeros = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            zeros++;
            continue;
        }
        set<int> yay = oddOccurPrimes(a[i]);
        ans += wow[yay];
        wow[yay]++;
    }

    ans += zeros * (n-zeros);
    ans += zeros * (zeros-1) / 2;

    cout << ans << '\n';
}