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

    ull m, n;
    cin >> m >> n;

    ull sum = 0;
    priority_queue<ull, vector<ull>, greater<ull>> maxDeprived;
    for(int i = 0; i < n; i++) {
        ull ai;
        cin >> ai;
        maxDeprived.push(ai);
        sum += ai;
    }

    ull toDeprive = 0;
    ull deprived = 0;
    ull ans = 0;

    while(!maxDeprived.empty() && sum > m) {
        ull curr = maxDeprived.top();

        if(sum - (curr-deprived)*maxDeprived.size() > m) {
            sum -= (curr-deprived)*maxDeprived.size();
            deprived = curr;
            while(!maxDeprived.empty() && maxDeprived.top() == deprived) {
                maxDeprived.pop();
                ans += (deprived*deprived);
            }
        }else {
            deprived += (sum - m) / maxDeprived.size();
            toDeprive = (sum - m) % maxDeprived.size();
            sum = m;
        }
    }

    ull group1 = toDeprive;
    ull group2 = maxDeprived.size() - toDeprive;

    ans += (deprived+1)*(deprived+1)*group1;
    ans += deprived*deprived*group2;

    cout << ans << '\n';
}