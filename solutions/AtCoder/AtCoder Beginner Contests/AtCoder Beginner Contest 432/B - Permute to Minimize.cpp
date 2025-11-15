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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    fastio;

    int x;
    cin >> x;

    vector<int> d;
    int cnt0 = 0;

    for(int num = x; num > 0; num/=10) {
        if(num%10 == 0) cnt0++;
        else d.push_back(num%10);
    }
    sort(d.begin(), d.end());

    cout << d[0];
    while(cnt0 > 0) {
        cout << 0;
        cnt0--;
    }
    for(int i = 1; i < d.size(); i++) cout << d[i];
    cout << '\n';
}