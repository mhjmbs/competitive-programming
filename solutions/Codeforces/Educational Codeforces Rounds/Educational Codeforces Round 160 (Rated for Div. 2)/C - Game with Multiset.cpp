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

bool canGet(int i, vector<int>& occur) {
    if(occur[i] > 0) {
        occur[i]--;
        return true;
    }

    if(i == 0) return false;

    return canGet(i-1, occur) && canGet(i-1, occur);
}

bool check(int w, vector<int> occur) {
    for(int i = 0; i < 32; i++) {
        if(w & (1 << i)) {
            if(!canGet(i, occur)) {
                return false;
            }
        }
    }

    return true;
}



int main() {
    fastio;

    int m;
    cin >> m;

    vector<int> occur(32, 0);

    for(int i = 0; i < m; i++) {
        int ti, vi;
        cin >> ti >> vi;

        if(ti == 1) {
            occur[vi]++;
        }else {
            cout << (check(vi, occur) ? "YES" : "NO") << '\n';
        }
    }
}