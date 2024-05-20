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

double h1, t1, h2, t2;

double getG(double h, double t, double d) {
    return 2*h/((t-d)*(t-d));
}

double solve(double a, double b, double c) {
    double delta = b*b - 4*a*c;
    double d1 = (-b + sqrt(delta))/(2*a);
    double d2 = (-b - sqrt(delta))/(2*a);
    return getG(h1,t1,d1) > 0 && getG(h2,t2,d1) > 0  && t1>d1 && t2>d1 ? d1 : d2;
}

int main() {
    fastio;

    cin >> h1 >> t1 >> h2 >> t2;

    cout << solve(h1-h2, -2*h1*t2 + 2*h2*t1, h1*t2*t2 - h2*t1*t1) << '\n';    
}