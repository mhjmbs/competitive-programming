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


int h, w, q;

int flip(int x) {
    return ~(x|~((1<<h)-1));
}

int main() {
    fastio;

    cin >> h >> w >> q;

    vector<string> grid(h);
    vector<int> col(w);

    for(string& row : grid) {
        cin >> row;
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] == '1') {
                col[j] ^= (1<<i);
            }
        }
    }

    vector<vector<int>> transf(1<<h, vector<int>(1<<h));

    for(int m1 = 0; m1 < (1<<h); m1++) {
        for(int m2 = 0; m2 < (1<<h); m2++) {
            int ans1 = 0, ans2 = 0;
            for(int i = 0; i < h; i++) {
                ans1 += bool((m1^m2) & (1<<i));
                ans2 += bool((~m1^m2) & (1<<i));
            }
            transf[m1][m2] = min(ans1,ans2+1);
        }
    }

    vector<int> dp(1<<h);

    for(int i = 0; i < w; i++) {
        for(int m = 0; m < (1<<h); m++) {
            dp[m] = dp[m] + transf[col[i]][m];
        }
    }

    //for(int m = 0; m < (1<<h); m++) {
    //    cout << m << ' ' << dp[m] << '\n';
    //}
    
    int ans = 1e9;
    for(int m = 0; m < (1<<h); m++) {
        ans = min(ans, dp[m]+__builtin_popcount(m));
    }
    cout << ans << '\n';

    vector<bool> row_flip(h);

    while(q--) {
        char op;
        cin >> op;

        ans = 1e9;

        if(op != 'R') {
            int i, j;
            if(op == 'P') cin >> i;
            cin >> j;
            i--,j--;

            int ccol = 0;
            for(int i = 0; i < h; i++) {
                if(row_flip[i]) ccol |= col[j]&(1<<i)^(1<<i);
                else ccol |= col[j]&(1<<i);
            }

            int ncol = (op == 'K') ? flip(ccol) : ccol^(1<<i);

            //cout << "here " << ccol << ' ' << ncol << '\n';
            //cout << dp[0] << '\n';
            for(int m = 0; m < (1<<h); m++) {
                dp[m] -= transf[ccol][m];
                dp[m] += transf[ncol][m];
                ans = min(ans, dp[m]+__builtin_popcount(m));
            }
            //cout << dp[0] << '\n';
            col[j] = (op == 'K') ? flip(col[j]) : col[j]^(1<<i);
        }else {
            int i;
            cin >> i;
            i--;
            vector<int> ndp(1<<h);
            for(int m = 0; m < (1<<h); m++) {
                ndp[m] = dp[m^(1<<i)];
                ans = min(ans, ndp[m]+__builtin_popcount(m));
            }
            row_flip[i] = !row_flip[i];
            swap(dp,ndp);
        }

        cout <<  ans << '\n';
    }
}
