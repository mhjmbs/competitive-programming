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

int n;
vector<int> a;
vector<vector<vector<int>>> memo;

bool canTree(bool leftChild, int parent, int first, int last) {
    if(memo[leftChild][first][last] != -1) return memo[leftChild][first][last];

    bool answer = false;

    for(int root = first; root <= last; root++) {
        answer = answer || 
        (
            gcd(a[root],parent) > 1 && 
            ( first > root-1 || canTree(true, a[root], first, root-1) ) && 
            ( root+1 > last || canTree(false, a[root], root+1, last) )
        );
    }

    return memo[leftChild][first][last] = answer;
}

int main(){
    fastio;
    
    cin >> n;

    a.resize(n);
    for(int&ai : a) cin >> ai;

    bool yes = false;

    memo.resize(2, vector<vector<int>>(n, vector<int>(n, -1)));

    yes = canTree(true, 0, 0, n-1);

    cout << (yes ? "Yes" : "No") << '\n';
}