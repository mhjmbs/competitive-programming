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

ll getSum(string& s) {
    ll ans = 0;
    int start = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+') {
            ans += stoll(string(s.begin()+start, s.begin()+i));
            start = i+1;
        }
    }

    ans += stoll(string(s.begin()+start, s.end()));

    return ans;
}

ll backtracking(string& s, int i) {
    ll ans = 0;
    ans += getSum(s);

    while(i < s.size()) {
        if(s[i-1] != '+') {
            string newS = string(s.begin(), s.begin()+i) + '+' + string(s.begin()+i, s.end());
            ans += backtracking(newS, i+1);
        }
        i++;
    }

    return ans;
}

int main() {
    fastio;

    string s;
    cin >> s;
    
    cout << backtracking(s,1) << '\n';
}