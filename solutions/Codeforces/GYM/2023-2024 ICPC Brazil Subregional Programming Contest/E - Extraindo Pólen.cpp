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

int digitSum(int x) {
    int ans = 0;
    while(x != 0) {
        ans += x%10;
        x/=10;
    }
    return ans;
}

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<int> freq(1e6+1, 0);
    for(int i = 0; i < n; i++) {
        int fi;
        cin >> fi;
        freq[fi]++;
    }

    int curr = 0;
    int ans = 0;

    for(int i = 1e6; i > 0; i--) {
        if(freq[i] == 0) continue;

        curr += freq[i];
        freq[i - digitSum(i)] += freq[i];
        freq[i] = 0;
    
        if(curr >= k) {
            ans = digitSum(i);
            break;
        }
    }

    cout << ans << '\n';
}