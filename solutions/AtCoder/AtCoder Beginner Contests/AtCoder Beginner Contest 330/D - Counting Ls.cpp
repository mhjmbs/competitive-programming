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

    int n;
    cin >> n;

    vector<string> grid(n);
    vector<vector<int>> rowPref(n+1, vector<int>(n+1, 0)), colPref(n+1, vector<int>(n+1, 0));

    for(string& s : grid)
    {
        cin >> s;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            rowPref[i][j] = rowPref[i][j-1] + (grid[i-1][j-1] == 'o' ? 1 : 0); 
        }
    }

    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            colPref[i][j] = colPref[i-1][j] + (grid[i-1][j-1] == 'o' ? 1 : 0);
        }
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(grid[i-1][j-1] == 'x') continue;

            int up = colPref[i-1][j];
            int down = colPref[n][j] - colPref[i][j];
            int left = rowPref[i][j-1];
            int right = rowPref[i][n] - rowPref[i][j];
        
            ans += up*left;
            ans += up*right;
            ans += down*left;
            ans += down*right;
        }
    }

    cout << ans << '\n';
}