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

char trump;

bool beats(string& a, string& b) {
    if(a[1] == trump && b[1] != trump) return true;
    if(a[1] != b[1]) return false;
    return a[0] > b[0];
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cin >> trump;

        vector<string> cards(2*n);
        for(string& c : cards) cin >> c;

        sort(cards.begin(), cards.end(),
        [](string a, string b) {
            if(a[1] != trump && b[1] == trump) return true;
            if(a[1] == trump && b[1] != trump) return false;
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        vector<bool> vis(2*n, false);
        vector<pair<string,string>> ans;
        ans.reserve(n);
        bool imp = false;

        for(int i = 0; i < 2*n; i++) {
            if(vis[i]) continue;
            vis[i] = true;
            string c = cards[i], c2 = "";
            for(int j = i+1; j < 2*n; j++) {
                if(vis[j]) continue;
                if(beats(cards[j], c)) {
                    c2 = cards[j];
                    vis[j] = true;
                    break;
                }
            }

            if(c2.empty()) imp = true;
            ans.emplace_back(c, c2);
        }

        if(imp) cout << "IMPOSSIBLE\n";
        else {
            for(auto [c1,c2] : ans) cout << c1 << ' ' << c2 << '\n';
        }
    }
}