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

        int posCount = 0;
        int negCount = 0;
        int zeroCount = 0;

        vector<int> a(n);
        for(int& ai : a) {
            cin >> ai;
            if(ai > 0) posCount++;
            else if(ai < 0) negCount++;
            else zeroCount++;
        }

        int k = 0;
        vector<pii> op;

        if(zeroCount == 0 && negCount % 2 == 0) {
            k++;
            op.emplace_back(1, 0);
        }

        cout << k << '\n';
        for(auto [i,x] : op) {
            cout << i << ' ' << x << '\n';
        }
    }
}