#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n;
    cin >> n;

    map<string,pdd> runners;

    for(int i = 0; i < n; i++)
    {
        string name;
        double t1, t2;
        cin >> name >> t1 >> t2;
        runners[name] = {t1,t2};
    }

    vector<string> ansNames(4, "");
    vector<double> ansTimes(4, 1e8);

    for(auto runner : runners)
    {
        vector<string> names(4);
        names[0] = runner.first;
        vector<double> times(4, 1e8);
        times[0] = runner.second.first;

        for(auto runner2 : runners)
        {
            if(runner2.first == names[0])
            {
                continue;
            }

            auto it = max_element(times.begin()+1, times.end());
            if(*it > runner2.second.second)
            {
                *it = runner2.second.second;
                names[it - times.begin()] = runner2.first;
            }
        }

        if(accumulate(ansTimes.begin(), ansTimes.end(), 0.0) > accumulate(times.begin(), times.end(), 0.0))
        {
            ansNames = names;
            ansTimes = times;
        }
    }

    cout << accumulate(ansTimes.begin(), ansTimes.end(), 0.0) << '\n';
    for(const string& name : ansNames)
    {
        cout << name << '\n';
    }
}