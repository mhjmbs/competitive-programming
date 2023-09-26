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



int main() {
    fastio;

    int n;
    cin >> n;

    vector<pair<pll,int>> people;

    for(int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        people.emplace_back(make_pair(a,b), i);
    }

    auto comp = [](pair<pll,int> a, pair<pll,int> b) {
        ll a1,a2,b1,b2;
        tie(a1,b1) = a.first;
        tie(a2,b2) = b.first;
        if(b1*(a2+b2) != b2*(a1+b1)) {
            return b1*(a2+b2) < b2*(a1+b1);
        }else {
            return a.second < b.second;
        }
    };

    sort(people.begin(), people.end(), comp);

    for(int i = 0; i < n; i++) {
        cout << people[i].second << (i != n-1 ? ' ' : '\n');
    }
}