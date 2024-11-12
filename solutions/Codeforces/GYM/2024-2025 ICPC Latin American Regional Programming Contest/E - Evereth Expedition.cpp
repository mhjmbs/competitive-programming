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

bool check(vector<int>& a) {
    int n = a.size();
    int high = max_element(a.begin(), a.end()) - a.begin();
    for(int i = 0, last = -1; i <= high; i++) {
        if(!(last < a[i])) return false;
        last = a[i];
    }
    for(int i = n-1, last = -1; i >= high; i--) {
        if(!(last < a[i])) return false;
        last = a[i];
    }
    return true;
}

void cant() {
    cout << "*\n";
    exit(0);
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    if(count(a.begin(), a.end(), 0) == n) {
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return 0;
    }

    set<int> st;
    for(int i = 1; i <= n; i++) st.insert(i);
    for(int ai : a) st.erase(ai);

    int l = 0, lc = 0, r = n-1, rc = n-1;
    while(a[lc] == 0) lc++;
    while(a[rc] == 0) rc--;

    while(lc != rc) {
        if(a[lc] < a[rc]) {
            int last = a[l];
            while(l < lc) {
                if(a[l] == 0) {
                    auto it = st.lower_bound(last);
                    if(it == st.end()) cant();
                    last = a[l] = *it;
                    st.erase(it);
                }
                l++;
            }
            do {
                lc++;
            }while(a[lc] == 0);
        }else {
            int last = a[r];
            while(rc < r) {
                if(a[r] == 0) {
                    auto it = st.lower_bound(last);
                    if(it == st.end()) cant();
                    last = a[r] = *it;
                    st.erase(it);
                }
                r--;
            }
            do {
                rc--;
            }while(a[rc] == 0);
        }
    }

    vector<int> a2 = a;
    set<int> st2 = st;

    int high = lc;
    for(int i = 0, last = -1; i <= high; i++) {
        if(a[i] == 0) {
            auto it = st.lower_bound(last);
            if(it == st.end()) cant();
            a[i] = *it;
            st.erase(it);
        }
        last = a[i];
    }
    for(int i = n-1, last = -1; i >= high; i--) {
        if(a[i] == 0) {
            auto it = st.lower_bound(last);
            if(it == st.end()) cant();
            a[i] = *it;
            st.erase(it);
        }
        last = a[i];
    }
    for(int i = n-1, last = -1; i >= high; i--) {
        if(a2[i] == 0) {
            auto it = st2.lower_bound(last);
            if(it == st2.end()) cant();
            a2[i] = *it;
            st2.erase(it);
        }
        last = a2[i];
    }
    for(int i = 0, last = -1; i <= high; i++) {
        if(a2[i] == 0) {
            auto it = st2.lower_bound(last);
            if(it == st2.end()) cant();
            a2[i] = *it;
            st2.erase(it);
        }
        last = a2[i];
    }

    if(check(a)) {
        for(int ai : a) cout << ai << ' ';
    }else if(check(a2)) {
        for(int ai : a2) cout << ai << ' ';
    }else {
        cout << "*";
    }
    cout << '\n';
}