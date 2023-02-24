#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds ;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    ordered_set os;
    for(int i = 0; i < x.size(); i++) os.insert(i);

    for(int i = 0, p; i < n; i++) {
        cin >> p;
        p--;
        auto it = os.find_by_order(p);
        cout << x[*it];
        os.erase(it); 
        if(i != n-1) cout << ' ';
        else cout << '\n';
    }
}