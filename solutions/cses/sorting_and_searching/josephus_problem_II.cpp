#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    ordered_set children;

    for(int i = 1; i <= n; i++) children.insert(i);

    int curr = 0;

    while(children.size() != 0) {
        int skip = k % children.size();
        curr = (curr+skip) % children.size();
        auto it = children.find_by_order(curr);
        children.erase(it);

        cout << *it;
        if(children.size() != 0) cout << ' ';
        else cout << '\n';
    }
}