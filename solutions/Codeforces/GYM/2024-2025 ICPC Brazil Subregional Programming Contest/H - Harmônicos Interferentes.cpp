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

string m, n;

bool solve() {
    int int_n = stoi(n, 0, 2);
    if(int_n == 0) return false;

    int r = 0;

    for(int i = 0; i < m.size(); i++) {
        r *= 2;
        r += m[i] == '1';
        if(r/int_n > 0) {
            r = r % int_n;
        }
    }

    return r == 0;
}

void backtracking(int i, vector<pii>& pos) {
    if(i == pos.size()) {
        if(solve()) {
            cout << m << '\n';
            exit(0);
        }
        return;
    }

    if(pos[i].first == 0) {
        m[pos[i].second] = '0';
        backtracking(i+1, pos);
        m[pos[i].second] = '1';
        backtracking(i+1, pos);
    }else {
        n[pos[i].second] = '0';
        backtracking(i+1, pos);
        n[pos[i].second] = '1';
        backtracking(i+1, pos);
    }
}

int main() {
    fastio;

    cin >> m >> n;
    
    vector<pii> pos;

    for(int i = 0; i < m.size(); i++) {
        if(m[i] == '*') pos.emplace_back(0, i);
    }
    for(int i = 0; i < n.size(); i++) {
        if(n[i] == '*') pos.emplace_back(1, i);
    }

    backtracking(0, pos);
}