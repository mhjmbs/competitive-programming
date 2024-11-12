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

int dist(string& a, string& b) {
    int count = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) count++;
    }
    return count;
}

int main() {
    fastio;

    int k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.size();

    if(k == 2) {
        string ns(s.size(), ' '), ns2(s.size(), ' ');
        for(int i = 0; i < s.size(); i++) {
            ns[i] = (i%2 == 0) ? '0' : '1';
            ns2[i] = (i%2 == 1) ? '0' : '1';
        }

        if(dist(s,ns) <= dist(s,ns2)) {
            cout << dist(s,ns) << ' ' << ns << '\n';
        }else {
            cout << dist(s,ns2) << ' ' << ns2 << '\n';
        }

        return 0;
    }

    char last = s[0];
    int i = 0, count = 0, moves = 0;

    while(i < n) {
        while(i+count < n && s[i+count] == last) {
            count++;
        }

        int j = i+k-1;

        while(j < i+count) {
            if(j == i+count-1) s[j-1] = (s[j-1] == '0') ? '1' : '0';
            else s[j] = (s[j] == '0') ? '1' : '0';
            moves++;
            j += k;
        };

        i = i+count;
        count = 1;
        last = (last == '0') ? '1' : '0';
    }

    cout << moves << ' ' << s << "\n";
}