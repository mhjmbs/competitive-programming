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

string solve(int k, int n) {
    string s(n, '-');
    int ck = k;

    if(n % 3 == 0) {
        s[n-1] = 'X';
        ck--;
    }

    for(int i = 0; i < n; i += 3) {
        s[i] = 'X'; 
        ck--;
    }

    for(int i = 6; i < n; i += 6) {
        if(ck <= 0) break;
        s[i-2] = 'X';
        s[i-3] = '-';
        s[i-4] = 'X';
        ck--;
    }

    if(n >= 4 && ck == 1 && s.substr(n-4, 4) == "--X-") {
        s[n-1] = 'X';
        s[n-2] = '-';
        s[n-3] = 'X';
        ck--;
    }

    if(ck == 0) return s;
    return "*";
}

int main() {
    fastio;

    int k, n;
    cin >> k >> n;

    string s1 = solve(k, n);
    string s2 = solve(k, n-1);

    if(s1 != "*") cout << s1;
    else if(s2 != "*") cout << '-' << s2;
    else cout << "*";
    cout << '\n';
}