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

set<vector<vector<int>>> vis;
int h, w;
vector<vector<int>> A, B;

void swapColumn(vector<vector<int>>& M, int j)
{
    for(int i = 0; i < h; i++)
    {
        swap(M[i][j], M[i][j+1]);
    }
}

int main() {
    fastio;

    cin >> h >> w;

    A.resize(h, vector<int>(w));
    B.resize(h, vector<int>(w));

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> B[i][j];
        }
    }

    queue<pair<vector<vector<int>>, int>> q;
    q.emplace(A, 0);
    vis.insert(A);

    int ans = INT_MAX;

    while(!q.empty())
    {
        auto [M, op] = q.front();
        q.pop();

        if(M == B) {
            ans = op;
            break;
        }

        for(int i = 0; i < h-1; i++)
        {
            M[i].swap(M[i+1]);
            if(vis.count(M) == 0)
            {
                q.emplace(M, op+1);
                vis.insert(M);
            }
            M[i].swap(M[i+1]);
        }

        for(int j = 0; j < w-1; j++)
        {
            swapColumn(M, j);
            if(vis.count(M) == 0)
            {
                q.emplace(M, op+1);
                vis.insert(M);
            }
            swapColumn(M, j);
        }
    }

    if(ans == INT_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}