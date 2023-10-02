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

        vector<int> a(n);
        set<int> mods;

        for(int &ai : a) {
            cin >> ai;
            mods.insert(ai % 10);
        }

        bool yes = false;

        if(mods.count(5) == 1 || mods.count(0) == 1) {
            for_each(a.begin(), a.end(), [](int &a){if(a % 10 == 5) a += 5;});
            yes = yes = all_of(a.begin(), a.end(), [&a](int ai) {return ai == a[0];});
        }else {
            for_each(a.begin(), a.end(), [](int &a){while(a % 10 != 2) a += a % 10;});
            yes = yes = all_of(a.begin(), a.end(), [&a](int ai) {return abs(ai-a[0]) % 20 == 0;});
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}