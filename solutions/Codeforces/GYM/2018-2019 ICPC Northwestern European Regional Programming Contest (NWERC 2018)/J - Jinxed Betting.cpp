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

int LOG(__int128_t x) {
    int ans = -1;
    int count = 0;
    while(x > 0) {
        if(x&1) ans = count;
        count++;
        x/=2;
    }

    return ans;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<__int128_t> p(n);
    for(int i = 0; i < n; i++) {
        ll inp;
        cin >> inp;
        p[i] = inp;
    }

    sort(p.rbegin(), p.rend());

    __int128_t ans = 0;
    __int128_t curr = p[1];
    __int128_t count = 1;

    for(int i = 2; i < n; i++) {
        p[i] += ans;

        __int128_t l = 0, r = 1e18, cycles = 0;

        while(l <= r) {
            __int128_t mid = (l+r)/2;
            if(p[i] + mid*(LOG(count)+1) >= curr + LOG(count)*mid) {
                cycles = mid;
                r = mid-1;
            }else {
                l = mid+1;
            }
        }

        if(curr + LOG(count)*cycles > p[0]) {
            break;
        }

        ans += (LOG(count)+1)*cycles;
        curr += LOG(count)*cycles;
        count++;
    }

    __int128_t l = 0, r = 1e18, cycles = 0;

    while(l <= r) {
        __int128_t mid = (l+r)/2;
        if(curr + LOG(count)*mid <= p[0]) {
            cycles = mid;
            l = mid+1;
        }else {
            r = mid-1;
        }
    }

    ans += (LOG(count)+1)*cycles;
    curr += LOG(count)*cycles;
    ans += p[0] - curr;

    cout << ll(ans) << '\n';
}