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

struct Weapon {
    int a;
    int b;
    int c;
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<Weapon> w(n);
    for(auto& [a,b,c] : w) cin >> a >> b >> c;

    auto comp = [](Weapon w1, Weapon w2) {
        return w1.a*w2.b + w1.b > w2.a*w1.b + w2.b;
    };

    sort(w.begin(), w.end(), comp);

    vector<int> dp(p+1, 0);
    int ans = 0;

    for(auto [a,b,c] : w) {
        for(int i = p; i >= 0; i--) {
            if(i-b < 0) continue;
            dp[i] = max(dp[i], dp[(i-b)/a] + c);
            ans = max(ans, dp[i]);
        }
    }

    cout << ans << '\n';
}