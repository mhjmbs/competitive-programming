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

string code;
vector<vector<int>> adjacencies;
vector<int> order;

void dfs(int node, int parent) {
    order.push_back(node);
    code.push_back('0');

    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dfs(adj,node);
    }

    code.push_back('1');
}

int main() {
    fastio;

    string s;
    cin >> s;

    string name;
    int id = 0;
    map<string,int> ni;
    map<int,string> in;

    if(s == "ENCODE") {
        int currP = -1;

        while(cin >> name) {
            if(name.back() == ':') {
                name.pop_back();
                if(ni.count(name) == 0) {
                    ni[name] = id;
                    in[id] = name;
                    id++;
                    adjacencies.push_back({});
                }
                currP = ni[name];
            }else {
                if(ni.count(name) == 0) {
                    ni[name] = id;
                    in[id] = name;
                    id++;
                    adjacencies.push_back({});
                }
                adjacencies[currP].push_back(ni[name]);
            }
        }

        dfs(0, -1);

        for(int i = 0; i < id; i++) {
            cout << in[order[i]] << '\n';
        }

        cout << code << '\n';
    }else {
        while(cin >> name) {
            if(isdigit(name[0])) {
                code = name;
                break;
            }

            ni[name] = id;
            in[id] = name;
            order.push_back(id);
            id++;
        }

        adjacencies.resize(id);
        vector<int> p(id, -1);

        int node = -1;
        int oi = -1;

        for(char c : code) {
            if(c == '0') {
                oi++;
                int newNode = order[oi];
                p[newNode] = node;
                if(node != -1) adjacencies[node].push_back(newNode);
                node = newNode;
            }else {
                node = p[node];
            }
        }

        for(int i = 0; i < id; i++) {
            if(adjacencies[i].empty()) continue;
            cout << in[i] << ": ";

            for(int adj : adjacencies[i]) {
                cout << in[adj] << ' ';
            }
            cout << '\n';
        }
    }
}