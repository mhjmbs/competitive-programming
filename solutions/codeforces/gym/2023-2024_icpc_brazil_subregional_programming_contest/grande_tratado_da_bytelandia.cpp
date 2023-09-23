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

#define f first
#define s second
#define pb push_back
#define sz size

int n;
pii v[int(1e5)];
map<pii, int> id;
vector<int> ans;

ll cross(pii a, pii b, pii c){
    pii v1={c.f-a.f, c.s-a.s};
    pii v2={b.f-a.f, b.s-a.s};
    return v1.f*v2.s-v1.s*v2.f;
}

void ch(){
    sort(v, v+n);
    vector<pii> upper, lower, convex;
    
    // a condição do cross será < quando incluir
    //colinear, senão <=

    for(int i=0; i<n; i++){
        while(sz(upper)>1 && cross(upper[sz(upper)-2], upper[sz(upper)-1], v[i])<0){
            upper.pop_back();
        }
        upper.pb(v[i]);
    }
    for(int i=n-1; i>=0; i--){
        while(sz(lower)>1 && cross(lower[sz(lower)-2], lower[sz(lower)-1], v[i])<0){
            lower.pop_back();
        }
        lower.pb(v[i]);
    }
    for(int i=0; i<sz(upper)-1; i++){
        convex.pb(upper[i]);
    }
    for(int i=0; i<sz(lower)-1; i++){
        convex.pb(lower[i]);
    }
    for(pii i:convex){
        ans.push_back(id[i]);
    }
}

int main() {
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        id[v[i]] = i+1;
    }

    ch();

    sort(ans.begin(), ans.end());
    int end = std::unique(ans.begin(), ans.end()) - ans.begin();

    for(int i = 0; i < end; i++) {
        cout << ans[i] << (i != ans.size()-1 ? ' ' : '\n');
    }
}