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

    int n;
    cin >> n;

    map<string ,int> tag;
    vector<string> file(n);

    for(int i = 0; i < n; i++) {
        cin >> file[i];
        tag[file[i]] = i;
    }

    vector<vector<int>> dist(n, vector<int>(n, 1e8)), last(n, vector<int>(n, -1));

    for(int i = 0, k; i < n; i++)
    {
        string file;
        cin >> file >> k;

        for(int j = 0; j < k; j++)
        {
            cin.ignore(7);

            while(true)
            {
                string file2;
                cin >> file2;
                
                if(file2.back() == ',')
                {
                    file2.pop_back();
                    dist[tag[file2]][tag[file]] = 1;
                    last[tag[file2]][tag[file]] = tag[file2];
                }
                else
                {
                    dist[tag[file2]][tag[file]] = 1;
                    last[tag[file2]][tag[file]] = tag[file2];
                    break;
                }
            }
        }
    }

    for(int m = 0; m < n; m++)
    {
        for(int u = 0; u < n; u++)
        {
            for(int v = 0; v < n; v++)
            {
                if(dist[u][v] > dist[u][m] + dist[m][v])
                {
                    dist[u][v] = dist[u][m] + dist[m][v];
                    last[u][v] = last[m][v];
                }
            }
        }
    }

    int ans = 1e8;
    int cycleBegin;
    for(int node = 0; node < n; node++)
    {
        if(ans > dist[node][node])
        {
            ans = dist[node][node];
            cycleBegin = node;
        }
    }

    if(ans == 1e8)
    {
        cout << "SHIP IT\n";
    }
    else
    {
        int node = cycleBegin;
        do
        {
            cout << file[node] << ' ';
            node = last[cycleBegin][node];
        }while(node != cycleBegin);
        cout << '\n';
    }
}