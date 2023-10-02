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

    int d, sumTime;
    cin >> d >> sumTime;
    vector<int> minTime(d), maxTime(d);

    for(int i = 0; i < d; i++) {
        cin >> minTime[i] >> maxTime[i];
        sumTime -= minTime[i];
    }

    for(int i = 0; i < d; i++) {
        if(sumTime > 0) {
            int diff = min(maxTime[i] - minTime[i], sumTime);
            sumTime -= diff;
            minTime[i] += diff;
        }
    }

    if(sumTime == 0) {
        cout << "YES\n";
        for(int i = 0; i < d; i++) {
            cout << minTime[i] << (i != d-1 ? ' ' : '\n');
        }
    }else {
        cout << "NO\n";
    }
}