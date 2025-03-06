#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <string>

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

int n;
vector<int> p;

pair<int,string> naive() {
    vector<int> can_l(n+1,1), can_r(n+1,1);

    for(int i = 1, mx = -1; i <= n; i++) {
        mx = max(mx, p[i]);
        can_l[i] = (mx == i);
    }

    for(int i = n, mn = 1e9; i >= 1; i--) {
        mn = min(mn, p[i]);
        can_r[i] = (mn == i);
    }

    int to_fix = 0, k = 1e9;
    int pref = 0, suff = 0;
    int sorted = true;

    for(int i = 1; i <= n; i++) {
        if(p[i] != i) {
            sorted = false;
            if(can_l[to_fix] && can_r[i]) {
                if(max(to_fix, n+1-i) + (to_fix == n+1-i) <= k) {
                    pref = to_fix;
                    suff = n+1-i;
                    if(pref == suff) pref++;
                    k = max(pref,suff);
                }
            }
            to_fix = i;
        }
    }

    if(sorted) return {0,""};

    if(to_fix < k) {
        k = to_fix;
        pref = to_fix;
        suff = 0;
    }

    string ans = string(k-1, (pref > suff) ? 'S' : 'P') + ((pref < suff) ? "S" : "P");
    return {k, ans};
}

void counting_sort(vector<int>::iterator begin, vector<int>::iterator end) {
    vector<int> count(1e6+1);
    for(auto it = begin; it != end; it++) {
        count[*it]++;
    }

    int num = 0;
    for(auto it = begin; it != end; it++) {
        while(count[num] == 0) {
            num++;
        }
        count[num]--;
        *it = num;
    }
}

pair<int,string> solve(vector<int> p, string ans) {
    int k = 1;

    while(k <= (n+1)/2) {
        if(ans.back() == 'P') {
            ans.push_back('S');
        }else {
            ans.push_back('P');
        }
        k++;
    }

    if(ans.back() == 'S') {
        counting_sort(p.begin()+1, p.begin()+1+k-1);
        counting_sort(p.end()-k, p.end());
    }else {
        counting_sort(p.end()-k+1, p.end());
        counting_sort(p.begin()+1, p.begin()+1+k);
    }

    int pref = 0, suff = n+1, l1 = -1, r1 = -1, l2 = -1, r2 = -1;
    deque<int> s1, s2;

    for(int i = 1; i <= n && p[i] == i; i++) pref++;
    for(int i = n; i >= 1 && p[i] == i; i--) suff--;

    l1 = pref+1;
    r2 = suff-1;

    for(int i = pref+1; i < n; i++) {
        r1 = i;
        s1.push_back(p[i]);
        if(p[i] > p[i+1]) break;
    }

    for(int i = r1+1; i < suff; i++) {
        s2.push_back(p[i]);
    }

    l2 = r1+1;

    auto access = [&](int i) {
        i--;
        i -= pref;
        if(i < s1.size()) return s1[i];
        i -= s1.size();
        return s2[i];
    };

    while(!(s1.empty() || s2.empty())) {
        k++;
        if(ans.back() == 'S') {
            while(l2 <= k && !s2.empty()) {
                l2++;
                pref++;
                l1++; r1++;
                s2.pop_front();
                while(!s1.empty() && access(l1) == pref+1) {
                    pref++;
                    l1++;
                    s1.pop_front();
                }
            }
            ans.push_back('P');
        }else {
            while(n+1-k <= r1 && !s1.empty()) {
                r1--;
                suff--;
                l2--; r2--;
                s1.pop_back();
                while(!s2.empty() && access(r2) == suff-1) {
                    suff--;
                    r2--;
                    s2.pop_back();
                }
            }
            ans.push_back('S');
        }

    }

    return {k,ans};
}

int main() {
    fastio;

    cin >> n;
    p.resize(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    pair<int, string> ans;

    if(n == 1) {
        ans = {0, ""};
    }else {
        ans = min({
            naive(),
            solve(p, "P"),
            solve(p, "S"),
        });
    }
    
    cout << ans.second + '.' << '\n';
}
