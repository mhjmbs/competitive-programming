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

string s;
set<string> ans;
void backtracking(int i) {
    if(i == s.size()) ans.insert(s); 
    for(int j = i; j < s.size(); j++) {
        swap(s[i],s[j]);
        backtracking(i+1);
        swap(s[i],s[j]);
    }
}

int main() {
    fastio;

    cin >> s;

    backtracking(0);

    cout << ans.size() << '\n';
    for(const string& curr : ans) cout << curr << '\n';
}