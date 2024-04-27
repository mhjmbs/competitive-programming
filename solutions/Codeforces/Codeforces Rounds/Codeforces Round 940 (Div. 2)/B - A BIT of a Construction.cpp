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
        int n, k;
        cin >> n >> k;

        if(n == 1) {
            cout << k << '\n';
            continue;
        }

        int firstZero = 32;
        int lastOne = 32;

        for(int i = 0; i < 32; i++) {
            if(k&(1<<i)) lastOne = i;
            else if(firstZero == 32) firstZero = i;
        }

        vector<int> a;
        a.reserve(n);

        if(firstZero != lastOne+1) {
            a.push_back((1<<lastOne)-1);
            k -= (1<<lastOne)-1;
            n--;
        }

        a.push_back(k);
        n--;

        while(n > 0) {
            a.push_back(0);
            n--;
        }

        for(int ai : a) cout << ai << ' ';
        cout << '\n';
    }
}