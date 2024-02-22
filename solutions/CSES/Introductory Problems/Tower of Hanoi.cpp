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

void move(int count, int source, int dest, int aux) {
    if(count == 0) return;

    move(count-1, source, aux, dest);

    cout << source << ' ' << dest << '\n';

    move(count-1, aux, dest, source);
}

int main() {
    fastio;

    int n;
    cin >> n;

    cout << int(pow(2,n))-1 << '\n';
    move(n, 1, 3, 2); 
}