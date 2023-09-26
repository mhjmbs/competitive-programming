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

int n, p = 31, m = 1e9+7;
string s;

vector<ll> h, p_pow;

bool check(int mid) {
    map<int,int> substr;
   
    for(int i = 1; i <= n-mid+1; i++) {
        int curr_h = ((h[i+mid-1] - h[i-1] + m) * ll(p_pow[n-mid+1-i])) % m;
        if(substr.count(curr_h) == 0) { 
            substr[curr_h] = i+mid-1;
        }else if(substr[curr_h] < i) {
            return true;
        }
    }

    return false;
}

int main() {
    fastio;

    cin >> n;
    cin >> s;

    p_pow.resize(n);
    p_pow[0] = 1;
    for(int i = 1; i < n; i++) {
        p_pow[i] = p_pow[i-1] * p % m;
    }

    h.resize(n+1);
    h[0] = 0;

    for(int i = 1; i <= n; i++) {
        h[i] = (h[i-1] + (s[i-1] - 'a' + 1) * p_pow[i-1]) % m;
    }

    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;

        if(check(mid)) {
            ans = mid;
            l = mid+1;
        }else {
            r = mid-1;
        }
    }
    cout << ans << '\n';
}