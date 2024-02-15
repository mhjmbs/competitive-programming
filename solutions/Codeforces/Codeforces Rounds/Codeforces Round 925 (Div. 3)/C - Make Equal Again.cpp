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
        for(int& ai : a) cin >> ai;

        int l = 0, r = n-1;

        while(l < n-1 && a[l] == a[l+1]) l++;
        while(r > 0 && a[r] == a[r-1]) r--;

        l++;
        r = n-1 - r + 1;

        if(l == n) cout << 0 << '\n';
        else if(a.front() == a.back()) cout << n - (l+r) << '\n';
        else cout << n - max(l,r) << '\n';
    }

    
}