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
using pip = pair<int, pair<int,int>>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

struct Interval {
    int id;
    int first;
    int last;

    Interval(int id, int first, int last)
        :id(id), first(first), last(last) {}
};

int main() {
    fastio;

    int q;
    cin >> q;

    while(q--) {
        string t;
        cin >> t;

        int n;
        cin >> n;

        bool possible = true;

        vector<Interval> intervals;

        for(int i = 0; i < n; i++) {
            string si;
            cin >> si;

            for(int ti = 0; ti <= int(t.size())-int(si.size()); ti++) {
                if(t.substr(ti, si.size()) == si) {
                    intervals.emplace_back(i+1, ti, ti+si.size()-1);
                }
            }
        }

        auto compare = [](Interval a, Interval b) {
            return a.first < b.first;
        };

        sort(intervals.begin(), intervals.end(), compare);

        vector<Interval> condensated;

        for(int i = 0, next = 0; i < intervals.size();) {
            
            if(next < intervals[i].first) {
                possible = false;
                break;
            }

            Interval best = intervals[i];

            while(i < intervals.size() && (intervals[i].first <= next || intervals[i].last <= best.last)) {
                if(best.last < intervals[i].last) {
                    best = intervals[i];
                }
                i++;
            }

            condensated.push_back(best);
            next = best.last+1;
        }

        int ans = condensated.size();

        for(int ti = 0, ci = 0; ti < t.size(); ti++, ci++) {
            if(ci >= condensated.size() || ti < condensated[ci].first) {
                possible = false;
                break;
            }else {
                ti = condensated[ci].last;
            }
        }

        if(possible) {
            cout << ans << '\n';
            for(Interval curr : condensated) {
                cout << curr.id << ' ' << curr.first+1 << '\n';
            }
        }else {
            cout << -1 << '\n';
        }
    }
}