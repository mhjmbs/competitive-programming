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



int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<int> s;
    s.reserve(n*k);
    vector<int> freq(n+1, k);
    freq[0] = 0;

    if(n%2 == 0) {
        s.push_back(n/2 + n%2);
        freq[n/2 + n%2]--;
    }else {
        while(freq[n/2 + n%2] > 0) {
            s.push_back(n/2 + n%2);
            freq[n/2 + n%2]--;
        }

        if(n/2 + n%2 - 1 > 0) {
            s.push_back(n/2 + n%2 - 1);
            freq[n/2 + n%2 - 1]--;
        }
    }

    for(int i = n; i > 0; i--) {
        while(freq[i] > 0) {
            s.push_back(i);
            freq[i]--;
        }
    }

    for(int si : s) cout << si << ' ';
    cout << '\n';
}