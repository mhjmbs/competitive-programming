#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
typedef tree<ll,null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;

int main() {
    fastio;

    int m;
    cin >> m;

    vector<ll> op(m+1, -1);
    multiordered_set mos;

    for(int i = 1, tq; i <= m; i++) {
        cin >> tq;
        if(tq == 1) {
            int a;
            cin >> a;
            mos.insert(a);
            op[i] = a;
        }else if(tq == 2) {
            int b;
            cin >> b;
            mos.erase(mos.upper_bound(op[b]));
        }else if (tq == 3) {
            int b, a;
            cin >> b >> a;
            mos.insert(a + op[b]);
            mos.erase(mos.upper_bound(op[b]));
            op[b] += a;
        }else {
            int b;
            cin >> b;
            cout << mos.order_of_key(op[b]) << '\n';
        }
    }
}