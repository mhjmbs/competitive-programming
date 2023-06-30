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
int inv_mod = 129032259;
string s;

vector<ll> h, rh, p_pow, inv_mod_pow;

int substr(int b, int e) {
    return ((h[e] - h[b-1] + m) * inv_mod_pow[b-1]) % m;
}

int rsubstr(int b, int e) {
    return ((rh[b-1] - rh[e] + m) * inv_mod_pow[n-e]) % m;
}

pii find_palindrome(int sz) {
    for(int i = 1; i <= n-sz+1; i++) {
        int b1 = i, b2;
        if(sz % 2 == 0) {
            b2 = i+sz/2;
        }else {
            b2 = i+sz/2+1;
        }

        if(substr(b1, b1+sz/2-1) == rsubstr(b2, b2+sz/2-1)) {
            return {i,sz};
        }
    }
    return {-1,-1};
}

int main() {
    fastio;

    cin >> s;
    n = s.size();

    p_pow.resize(n);
    inv_mod_pow.resize(n);
    p_pow[0] = inv_mod_pow[0] = 1;
    for(int i = 1; i < n; i++) {
        p_pow[i] = p_pow[i-1] * p % m;
        inv_mod_pow[i] = inv_mod_pow[i-1] * inv_mod % m;
    }

    h.resize(n+1);
    h[0] = 0;
    for(int i = 1; i <= n; i++) {
        h[i] = (h[i-1] + (s[i-1] - 'a' + 1) * p_pow[i-1]) % m;
    }

    rh.resize(n+1);
    h[n] = 0;

    for(int i = n-1; i >= 0; i--) {
        rh[i] = (rh[i+1] + (s[i] - 'a' + 1) * p_pow[n-1-i]) % m;
    }

    int l = 1, r = n/2, best = -1;
    pii ans = {-1,-1};

    while(l <= r) {
        int mid = (l+r)/2;
        int sz = 2*mid;

        pii pal = find_palindrome(sz);

        if(pal != make_pair(-1,-1)) {
            best = sz;
            ans = pal;
            l = mid+1;
        }else {
            r = mid-1;
        }
    }

    l = 0, r = n/2;

    while(l <= r) {
        int mid = (l+r)/2;
        int sz = 2*mid+1;

        pii pal = find_palindrome(sz);

        if(pal != make_pair(-1,-1)) {
            if(sz > best) {
                best = sz;
                ans = pal;
            }
            l = mid+1;
        }else {
            r = mid-1;
        }
    }

    cout << s.substr(ans.first-1, ans.second) << '\n';
}