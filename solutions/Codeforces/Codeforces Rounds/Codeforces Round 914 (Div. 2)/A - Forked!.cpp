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

int a, b;
int xk, yk;
int xq, yq;
int d[] = {-1,1};

bool reachesQueen(int x, int y)
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            int x1 = x+ a*d[i];
            int y1 = y+ b*d[j];
            int x2 = x+ b*d[i];
            int y2 = y+ a*d[j];

            if(x1 == xq && y1 == yq || x2 == xq && y2 == yq)
            {
                return true;
            }
        }
    }

    return false;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--)
    {
        cin >> a >> b;
        cin >> xk >> yk;
        cin >> xq >> yq;

        set<pii> ans;

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                int x1 = xk+ a*d[i];
                int y1 = yk+ b*d[j];
                int x2 = xk+ b*d[i];
                int y2 = yk+ a*d[j];

                if(reachesQueen(x1, y1))
                {
                    ans.emplace(x1,y1);
                }
                if(reachesQueen(x2,y2))
                {
                    ans.emplace(x2,y2);
                }
            }
        }

        cout << ans.size() << '\n';
    }
}