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

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int t1 = m, t2 = 0, usedT1 = 0, usedT2 = 0;

    for(char c : s)
    {
        if(c == '0')
        {
            t1 += usedT1;
            t2 += usedT2;
            usedT1 = usedT2 = 0;
        }
        else if(c == '1')
        {
            if(t1 > 0){
                t1--;
                usedT1++;
            }
            else{
                if(t2 > 0) t2--;
                usedT2++;
            }
        }
        else
        {
            if(t2 > 0) t2--;
            usedT2++;
        }
    }

    cout << t1 + t2 + usedT1 + usedT2 - m << '\n';
}