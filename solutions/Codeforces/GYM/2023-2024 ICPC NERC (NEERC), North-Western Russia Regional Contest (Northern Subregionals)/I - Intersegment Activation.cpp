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

int n;
int k, ck;
bool to_read = false;

vector<int> backflips;

void flip(int l, int r) {
    cout << l << ' ' << r << endl;
    to_read = true;
}

int query() {
    int ans;
    cin >> ans;
    to_read = false;
    return ans;
}

void solve(int l, int r) {
    if(r == n+1) {
        if(to_read) ck = query();
        if(ck == n) exit(0);
        if(ck > k) {
            k = ck;
            fill(backflips.begin(), backflips.end(), false);
        }
        return;
    }

    solve(l, r+1);
    flip(l,r);
    backflips[r] = !backflips[r];
    solve(l, r+1);
}

int main() {
    fastio;

    cin >> n;

    int i = 1;
    cin >> k;
    ck = k;
    backflips.resize(n+1);

    while(i <= n) {
        fill(backflips.begin(), backflips.end(), false);
        solve(i, i);
        for(int j = i; j <= n; j++) {
            if(backflips[j]) {
                if(to_read) ck = query();
                flip(i,j);
            }
        }
        i++;
    }
}