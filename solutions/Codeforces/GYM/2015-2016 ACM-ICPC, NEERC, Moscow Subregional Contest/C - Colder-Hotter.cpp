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

    int x = 0, y = 0, isBetter;
    cout << x << ' ' << y << endl;
    cin >> isBetter;

    int l = 0, r = 1e9;

    while(l < r) {
        cout << r << ' ' << y << endl;
        cin >> isBetter;

        if(isBetter) {
            l = (l+r)/2 + 1;
            x = l;
        }else {
            r = (l+r)/2;
        }

        cout << x << ' ' << y << endl;
        cin >> isBetter;
    }

    l = 0, r = 1e9;

    while(l < r) {
        cout << x << ' ' << r << endl;
        cin >> isBetter;

        if(isBetter) {
            l = (l+r)/2 + 1;
            y = l;
        }else {
            r = (l+r)/2;
        }

        cout << x << ' ' << y << endl;
        cin >> isBetter;
    }

    cout << "A " << x << ' ' << y << endl;
}