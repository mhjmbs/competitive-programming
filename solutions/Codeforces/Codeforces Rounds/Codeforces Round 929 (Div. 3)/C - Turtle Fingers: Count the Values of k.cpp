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
        int a, b, l;
        cin >> a >> b >> l;

        set<int> k;

        for(int x = 0; x <= 32; x++) {
            int currL = l;
            bool can = true;

            for(int i = 0; i < x; i++) {
                if(currL % a != 0) {
                    can = false;
                    break;
                }
                currL /= a;
            }

            if(!can) continue;

            k.insert(currL);
            while(currL % b == 0) {
                currL /= b;
                k.insert(currL);
            }
        }

        cout << k.size() << '\n';
    }
}