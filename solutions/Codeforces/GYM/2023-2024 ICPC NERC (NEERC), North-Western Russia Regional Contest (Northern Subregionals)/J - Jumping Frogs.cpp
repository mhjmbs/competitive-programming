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

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int& ai : a) cin >> ai;
    for(int& bi : b) cin >> bi;

    int i = 0, j = 0;
    int mx = 0;

    while(i < n && j < n) {
        if(a[i] > b[j]) {
            i++,j++;
            mx++;
        }else {
            i++;
        }
    }

    i = n-1, j = n-1;
    int mn = n;

    while(i >= 0 && j >= 0) {
        if(a[i] < b[j]) {
            i--,j--;
            mn--;
        }else {
            i--;
        }
    }

    cout << mx-mn+1 << '\n';

    for(int i = mn; i <= mx; i++) {
        cout << i << ' ';
    }
    cout << '\n';
}