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

ll h, w, n;

bool inbounds(ll i, ll j) {
    return 1 <= i && i <= h && 1 <= j && j <= w; 
}

int main() {
    fastio;

    cin >> h >> w >> n;

    set<pii> pts;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pts.emplace(a,b);
    }

    set<pii> vis;
    vector<ll> ans(10, 0);

    for(auto p : pts) {
        auto [i,j] = p;

        for(int ti = i-2; ti <= i; ti++) {
            for(int tj = j-2; tj <= j; tj++) {
                if(!inbounds(ti,tj) || vis.count({ti,tj}) == 1) continue;
                vis.emplace(ti,tj);
                int blackCount = 0;
                bool rectangleExists = true;
                for(int di = 0; di <= 2; di++) {
                    for(int dj = 0; dj <= 2; dj++) {
                        int ni = ti+di, nj = tj+dj;
                        if(inbounds(ni,nj)) {
                            if(pts.count({ni,nj}) == 1) blackCount++;
                        }else {
                            rectangleExists = false;
                        }
                    }
                }
                if(rectangleExists) ans[blackCount]++;
            }
        }
    }

    ans[0] = (h-2)*(w-2);

    for(int i = 1; i <= 9; i++) {
        ans[0] -= ans[i];
    }

    for(ll currAns : ans) {
        cout << currAns << '\n';
    }
}