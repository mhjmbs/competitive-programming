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

    int q;
    cin >> q;

    map<int,int> bag;

    while(q--) {
        int t;
        cin >> t;

        switch(t) {
            case 1: {
                int x;
                cin >> x;
                bag[x]++;
                break;
            }
            case 2: {
                int x;
                cin >> x;
                bag[x]--;
                if(bag[x] == 0) bag.erase(x);
                break;
            }
            case 3: {
                cout << bag.size() << '\n';
            }
        }
    }
}