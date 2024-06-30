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

    string s;
    cin >> s;

    vector<int> bla;
    bla.reserve(s.size()/2);

    for(int i = 0; i < s.size(); i+=2) {
        if(s[i] == '<') bla.push_back(0);
        else bla.push_back(1);
    }

    stack<int> st;

    string ans;
    ans.reserve(bla.size());

    for(int curr : bla) {
        if(!st.empty() && curr == !st.top()) {
            st.pop();
            ans.push_back(']');
        }else {
            st.push(curr);
            ans.push_back('[');
        } 
    }

    if(st.empty()) cout << ans << '\n';
    else cout << "Keine Loesung\n";
}