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

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    fastio;

    string s, f;
    cin >> s >> f;

    for(char& c : s) c = tolower(c);
    for(char& c : f) c = tolower(c);

    int i = 0, j = 0;

    while(i < s.size() && j < f.size()) {
        if(s[i] == f[j]) {
            i++, j++;
        }else {
            if(is_vowel(f[j])) {
                j++;
            }else {
                cout << "Different\n";
                return 0;
            }
        }
    }

    while(j < f.size() && is_vowel(f[j])) {
        j++;
    }

    if(i < s.size() || j < f.size()) {
        cout << "Different\n";
    }else {
        cout << "Same\n";
    }
}