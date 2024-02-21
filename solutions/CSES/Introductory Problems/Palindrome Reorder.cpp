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



int main() {
    fastio;

    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for(char c : s) freq[c-'A']++;

    int odd;
    int oddCount = 0;

    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 == 1) {
            odd = 'A'+i;
            oddCount++;
            freq[i]--;
        }
    }

    deque<char> ans;

    if(oddCount > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }else if(oddCount == 1) {
        ans.push_back(odd);
    }

    for(int i = 0; i < 26; i++) {
        while(freq[i] > 0) {
            ans.push_front('A'+i);
            ans.push_back('A'+i);
            freq[i] -= 2;
        }
    }

    while(!ans.empty()) {
        cout << ans.front();
        ans.pop_front();
    }
    cout << '\n';
}