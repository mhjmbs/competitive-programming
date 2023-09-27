#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds ;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    ordered_set os;

    for(int &pi : p) {
        cin >> pi;
        os.insert(pi);
    }

    for(int i = 0; i < q; i++) {
        char tq;
        cin >> tq;

        if(tq == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            os.erase(os.upper_bound(p[k]));
            p[k] = x;
            os.insert(x);
        }else {
            int a, b;
            cin >> a >> b;
            int oa = os.order_of_key(a), ob = os.order_of_key(b+1);
            cout << ob-oa << '\n';
        }
    }
}