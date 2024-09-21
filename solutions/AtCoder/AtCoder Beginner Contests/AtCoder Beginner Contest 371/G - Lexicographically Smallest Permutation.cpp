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

vector<int> apply(vector<int>& a, vector<int>& p) {
    vector<int> ans(a.size());
    for(int i = 1; i < a.size(); i++) ans[i] = a[p[i]];
    return ans;
}

vector<int> binExp(vector<int> p, int k) {
    vector<int> ans(p.size());
    iota(ans.begin(), ans.end(), 0);
    for(int i = 0; i < 18; i++) {
        if(k & (1<<i)) ans = apply(ans, p);
        p = apply(p, p);
    }
    return ans;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n+1), p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int to_fix = 1; to_fix <= n; to_fix++) {
        int best = a[to_fix], best_count = 0;
        int curr = to_fix;
        int count = 0;

        do{
            curr = p[curr];
            count++;
            if(a[curr] < best) {
                best = a[curr];
                best_count = count;
            }
        }while(curr != to_fix);

        if(count == 1) continue;

        vector<int> best_p = binExp(p, best_count);

        vector<int> new_a(n+1);
        for(int i = 1; i <= n; i++) new_a[i] = a[best_p[i]];
        swap(a,new_a);

        p = binExp(p, count);
    }

    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}