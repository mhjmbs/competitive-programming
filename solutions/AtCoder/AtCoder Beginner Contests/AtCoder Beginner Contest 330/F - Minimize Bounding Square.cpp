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
ll k;

vector<pll> x, y;

ll fixCoord(int side, vector<pll>& coord)
{
    int l = 0, r = coord.size()-1;
    int leftAccum = 0, rightAccum = 0;
    ll op = 0;

    while(l < r && coord[r].first - coord[l].first > side)
    {
        if(coord[l].second + leftAccum <= coord[r].second + rightAccum)
        {
            op += (coord[l+1].first - coord[l].first) * (coord[l].second + leftAccum);
            
            if(coord[r].first - coord[l+1].first <= side)
            {
                op -= (side - (coord[r].first - coord[l+1].first)) * (coord[l].second + leftAccum);
            }

            leftAccum += coord[l].second;
            l++;
        }
        else
        {
            op += (coord[r].first - coord[r-1].first) * (coord[r].second + rightAccum);

            if(coord[r-1].first - coord[l].first <= side)
            {
                op -= (side - (coord[r-1].first - coord[l].first)) * (coord[r].second + rightAccum);
            }

            rightAccum += coord[r].second;
            r--;
        }
    }

    return op;
}

bool canMakeSquare(int side)
{
    ll opHorizontal = fixCoord(side, x);
    ll opVertical = fixCoord(side, y);

    return opHorizontal + opVertical <= k;
}

int main() {
    fastio;

    cin >> n >> k;

    map<int,int> mpX, mpY;

    for(int i = 0, xi, yi; i < n; i++)
    {
        cin >> xi >> yi;
        mpX[xi]++;
        mpY[yi]++;
    }

    for(auto coordFreq: mpX)
    {
        x.push_back(coordFreq);
    }

    for(auto coordFreq: mpY)
    {
        y.push_back(coordFreq);
    }

    int l = 0, r = 1e9, ans = -1;
    while(l <= r)
    {
        int m = (l+r)/2;
        
        if(canMakeSquare(m))
        {
            ans = m;
            r = m-1;
        }
        else
        {
            l = m+1;
        }
    }

    cout << ans << '\n';
}