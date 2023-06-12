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

vector<vector<double>> multiply(vector<vector<double>> &a, vector<vector<double>> &b) {
    vector<vector<double>> result(2, vector<double>(2));
    result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    result[1][0] = a[1][1] * b[1][0] + a[1][0] * b[0][0];
    result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    return result;
}

int main() {
    fastio;

    int n;
    double p;
    cin >> n >> p;

    vector<vector<double>> dp = 
    {
        {1,0},
        {0,0}
    };

    vector<vector<double>> curr_pow =
    {
        {1-p,p},
        {p,1-p}
    };

    while(n != 0) {
        if(n % 2 == 1) {
            dp = multiply(dp, curr_pow);
        }
        curr_pow = multiply(curr_pow, curr_pow);
        n/=2;
    }

    cout << dp[0][0] + dp[1][0] << '\n';
}