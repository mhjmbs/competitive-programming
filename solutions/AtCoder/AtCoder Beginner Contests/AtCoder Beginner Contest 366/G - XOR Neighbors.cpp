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

using bs = bitset<64>;
int gauss(vector<bs> A, int m, bs& x) {
    int n = A.size();
    vector<int> pivot(m, -1);
    for(int i = 0, j = 0; i < n && j < m; j++) {
        if(!(A[i][j])) {
            for(int k = i+1; k < n; k++) {
                if(A[k][j]) {
                    swap(A[i],A[k]);
                    break;
                }
            }
        }

        if(!A[i][j]) continue;
        pivot[j] = i;

        for(int k = i+1; k < n; k++) {
            if(i != k && A[k][j]) A[k] ^= A[i];
        }

        i++;
    }

    for(int i = 0; i < m; i++) x[i] = 0;

    for(int j = m-1; j >= 0; j--) {
        if(pivot[j] == -1) continue;
        int sum = 0;
        for(int k = m-1; j < k; k--) sum ^= A[pivot[j]][k]*x[k];
        sum ^= A[pivot[j]][m];
        x[j] = sum;
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum ^= A[i][j]*x[j];
        }
        if(sum != A[i][m]) return 0;
    }

    return *min_element(pivot.begin(), pivot.end()) == -1 ? 2 : 1;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<bs> A(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        A[u][v] = 1;
        A[v][u] = 1;
    }

    vector<ll> x(n);

    for(int i = 0; i < n; i++) {
        A[n] = (1ll<<i) | (1ll<<n);

        bs ans;
        int is_determinate = gauss(A, n, ans);

        if(!is_determinate) {
            cout << "No\n";
            return 0;
        }

        for(int j = 0; j < n; j++) {
            x[j] |= (ll(ans[j]) << i);
        }
    }

    cout << "Yes\n";
    for(ll xi : x) cout << xi << ' ';
    cout << '\n';
}