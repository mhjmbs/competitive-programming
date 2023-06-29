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

    int t;
    cin >> t;

    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;
        int sum = 0;
        vector<int> ans;
        if(x != 1) {
            for(; sum < n; sum++) {
                ans.push_back(1);
            }
        }else if(k >= 2) {
            for(; sum < n; sum += 2) {
                ans.push_back(2);
            }
        }

        if(sum == n) {
            cout << "YES\n";
            cout << ans.size() << '\n';
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i] << (i == ans.size()-1 ? '\n' : ' ');
            }
        }else {
            ans.pop_back();
            sum -= 2;

            if(!ans.empty()) {
                ans.pop_back();
                sum -= 2;

                if(k >= 3) {
                    ans.push_back(3);
                    sum += 3;

                    cout << "YES\n";
                    cout << ans.size() << '\n';
                    for(int i = 0; i < ans.size(); i++) {
                        cout << ans[i] << (i == ans.size()-1 ? '\n' : ' ');
                    }
                }else {
                    cout << "NO\n";
                }
            }else {
                cout << "NO\n";
            }
        }
    }
}