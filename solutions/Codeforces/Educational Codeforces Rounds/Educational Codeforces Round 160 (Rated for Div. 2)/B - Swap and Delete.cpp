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
        string s, t;
        cin >> s;
        t = s;

        set<int> zeroPos, onePos;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') zeroPos.insert(i);
            else onePos.insert(i);
        }

        int begin;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0' && t[i] == '0') {
                if(!onePos.empty()) {
                    zeroPos.insert(*onePos.begin());
                    zeroPos.erase(i);
                    t[*onePos.begin()] = '0';
                    t[i] = '1';
                    onePos.erase(onePos.begin());
                }else {
                    begin = i;
                    break;
                }
            }else if(s[i] == '1' && t[i] == '1') {
                if(!zeroPos.empty()) {
                    onePos.insert(*zeroPos.begin());
                    onePos.erase(i);
                    t[*zeroPos.begin()] = '1';
                    t[i] = '0';
                    zeroPos.erase(zeroPos.begin());
                }else {
                    begin = i;
                    break;
                }
            }else if(t[i] == '1') {
                onePos.erase(onePos.begin());
            }else if(t[i] == '0') {
                zeroPos.erase(zeroPos.begin());
            }
        }

        int ans = abs(int(onePos.size()) - int(zeroPos.size()));
        cout << ans << '\n';
    }
}