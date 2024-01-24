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

int n;
const int m = 998244353; 
vector<int> a;
vector<vector<ll>> last, curr, pref;
 
void solve(int num) {
    curr[num][true] = (( pref[200][true] - pref[num-1][true] ) + m + last[num][false] ) % m;

    curr[num][false] = (pref[num-1][true] + pref[num-1][false]) % m;
}

int main() {
    fastio;
    
    cin >> n;
 
    a.resize(n);
    for(int& ai: a) cin >> ai;
 
    last.resize(201, vector<ll>(2, 0));
    curr.resize(201, vector<ll>(2, 0));
    pref.resize(201, vector<ll>(2, 0));
 
    if(a[0] != -1) {
        last[a[0]][false] = 1;
    }else {
        for(int num = 1; num <= 200; num++) {
            last[num][false] = 1;
        }
    }
 
    for(int i = 1; i < n; i++) {

        for(int i = 1; i <= 200; i++) {
            pref[i][true] = (pref[i-1][true] + last[i][true]) % m;
            pref[i][false] = (pref[i-1][false] + last[i][false]) % m;
        }

        if(a[i] != -1) {
            solve(a[i]);
        }else {
            for(int num = 1; num <= 200; num++) {
                solve(num);
            }
        }

        swap(last, curr);
        fill(curr.begin(), curr.end(), vector<ll>(2,0));
    }
 
    ll ans = 0;
 
    for(int num = 1; num <= 200; num++) {
        ans = (ans + last[num][true]) % m;
    }
 
    cout << ans << '\n';
}