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
     
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    const int n = 1e8;
    bool is_p[n+1];
     
    int main() {
        fastio;
        
        fill(is_p+2, is_p+n, true);
     
        for(int i = 2, cnt = 0; i*i <= n; i++) {
            if(is_p[i]) {
                for(int j = i*i; j <= n; j+=i) {
                    is_p[j] = false;
                }
            }
        }
     
        for(int i = 0, cnt = 0; i <= n; i++) {
            if(is_p[i]) {
                cnt++;
                if(cnt == 1) {
                    cout << i << '\n';
                }else if(cnt == 100) {
                    cnt = 0;
                }
            }
        }
    } 