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

struct SuffixArray {
    int n, classes = 256;
    vector<int> sa, c, count;

    SuffixArray(string s) : n(s.size()+1), sa(n), c(n), count(max(n,classes)) {
        s += '$';
        
        for(char c : s) {
            count[(c != '$') ? c-'a'+1 : 0]++;
        }

        for(int i = 0; i < n; i++) {
            c[i] = (s[i] != '$') ? s[i]-'a'+1 : 0;
        }
        
        for(int i = 1; i < classes; i++) {
            count[i] += count[i-1];
        }

        for(int i = n-1; i >= 0; i--) {
            sa[count[c[i]]-1] = i;
            count[c[i]]--;
        }

        for(int k = 0; (1<<k) < n; k++) {
            vector<int> nsa(n), nc(n);
            
            for(int i = 0; i < n; i++) nsa[i] = ((sa[i]-(1<<k))%n+n)%n;

            fill(count.begin(), count.begin()+classes, 0);
            for(int i = 0; i < n; i++) count[c[i]]++;
            for(int i = 1; i < classes; i++) count[i] += count[i-1];
            for(int i = n-1; i >= 0; i--) {
                sa[count[c[nsa[i]]]-1] = nsa[i]; 
                count[c[nsa[i]]]--;
            }

            classes = 1;
            for(int i = 1; i < n; i++) {
                nc[sa[i]] = nc[sa[i-1]];
                if(c[sa[i]] != c[sa[i-1]]) nc[sa[i]]++;
                else if(c[(sa[i]+(1<<k))%n] != c[(sa[i-1]+(1<<k))%n]) nc[sa[i]]++;
                classes += nc[sa[i]] != nc[sa[i-1]];
            }

            swap(c,nc);
        }
    }
};

int main() {
    fastio;

    string s;
    cin >> s;

    SuffixArray sa(s);

    for(int i : sa.sa) cout << i << ' ';
    cout << '\n';
}