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
using tllll = tuple<ll,ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll f(ll a, ll b, ll c) {
    return a*b + a*c + b*c;
}

int main() {
    fastio;

    int n, K;
    cin >> n >> K;

    vector<int> a(n), b(n), c(n);

    for(int& ai : a) cin >> ai;
    for(int& bi : b) cin >> bi;
    for(int& ci : c) cin >> ci;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    
    priority_queue<tllll> q;
    set<tiii> vis;

    q.emplace(f(a[0],b[0],c[0]),0,0,0);
    vis.emplace(0,0,0);
    int count = 0;

    while(!q.empty()) {
        auto [curr, i, j, k] = q.top();
        q.pop();
        
        if(++count == K) {
            cout << curr << '\n';
            break;
        }
        
        auto enqueue = [&](int i, int j, int k) {
            if(i < n && j < n && k < n && vis.count({i,j,k}) == 0) {
                q.emplace(f(a[i],b[j],c[k]),i,j,k);
                vis.emplace(i,j,k);
            }   
        };
        
        enqueue(i+1,j,k);
        enqueue(i,j+1,k);
        enqueue(i,j,k+1);
    }
}
