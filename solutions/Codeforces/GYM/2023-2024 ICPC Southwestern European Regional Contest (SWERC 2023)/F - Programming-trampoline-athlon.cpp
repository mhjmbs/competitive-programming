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



int main() {
    fastio;

    int n;
    cin >> n;

    vector<vector<string>> codes(101);

    for(int i = 0; i < n; i++) {
        string code;
        cin >> code;

        int p;
        cin >> p;

        vector<int> e(6);
        for(int& ei : e) cin >> ei;
        sort(e.begin(), e.end());

        int score = p*10 + accumulate(e.begin()+1, e.end()-1, 0);
        codes[score].push_back(code);
    }

    int printed = 0;
    int score = 100;

    while(score >= 0 && printed <= 2) {
        for(const string& code : codes[score]) {
            cout << code << ' ' << score << '\n';
            printed++;
        }
        score--;
    }
}