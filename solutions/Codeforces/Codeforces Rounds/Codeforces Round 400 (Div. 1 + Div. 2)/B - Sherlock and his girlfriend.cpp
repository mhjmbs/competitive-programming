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

vector<int> c;

vector<int> sieve(int n) {
    vector<int> is_p(n+1, true);
    is_p[0] = is_p[1] = false;
    
    for(int i = 2; i <= n; i++) {
        if(is_p[i]) {
            for(int j = 2*i; j <= n; j+=i) {
                is_p[j] = false;
                if(c[i] == c[j]) c[j]++;
            }
        }
    }

    return is_p;
}

int main() {
    fastio;

    int n;
    cin >> n;
    n++;

    c.resize(n+1, 1);

    sieve(n);

    cout << *max_element(c.begin(), c.end()) << '\n';

    for(int i = 2; i <= n; i++) {
        cout << c[i] << ' '; 
    }
    cout << '\n';
}