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

    int n, q;
    cin >> n >> q;

    ordered_set os;
    map<int,int> freq;

    vector<int> a(n);
    for(int &ai : a) {
        cin >> ai;
        os.insert(ai);
        freq[ai]++;
    }

    while(q--)
    {
        int i, x;
        cin >> i >> x;
        i--;

        freq[a[i]]--;
        if(freq[a[i]] == 0)
        {
            os.erase(a[i]);
        }

        os.insert(x);
        freq[x]++;
        a[i] = x;

        int l = 0, r = os.size()-1, ans = -1;

        while(l <= r)
        {
            int m = (l+r)/2;
            auto it = os.find_by_order(m);

            if(m == *it)
            {
                ans = m;
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }

        if(ans == -1)
        {
            cout << 0 << '\n';
        }else
        {
            cout << ans+1 << '\n';
        }
    }
}