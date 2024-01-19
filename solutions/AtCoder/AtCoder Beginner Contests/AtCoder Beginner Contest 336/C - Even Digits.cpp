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

ll findOrder(string num) {
    if(num == "") return -1;
    
    ll unlimited = (num[0] - '0') / 2;

    for(int i = 1; i < num.size(); i++) {
        unlimited = unlimited * 5 + (num[i] - '0')/2;
    }

    return unlimited + 1;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    string num(18, '0');

    for(int d = 0; d < 18; d++) {
        for(int nd = 8; nd >= 0; nd -= 2) {
            num[d] = '0' + nd;
            if(findOrder(num) <= n) break;
        }
    }

    cout << stoll(num) << '\n';
}