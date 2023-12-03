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

    int tc;
    cin >> tc;

    while(tc--)
    {
        ll n, P, l, t;
        cin >> n >> P >> l >> t;

        int taskCount = (n-1)/7 + 1;

        int left = 0, right = n, ans = -1;

        while(left <= right)
        {
            int mid = (left + right)/2;
            ll points = mid*l + min(taskCount, 2*mid)*t;
            if(points >= P)
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        cout << n-ans << '\n';
    }
    
}