#include "bits/stdc++.h"
    
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
    
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
    
int main() {
    fastio;
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int,vector<string>>> grids(k+1, {0, vector<string>(n)});
    
    int counter = 1;
    for(auto &grid : grids) {
        grid.first = counter;
        for(int i = 0; i < n; i++) {
            cin >> grid.second[i];
        }
        counter++;
    }
    
    auto comp = [n,m](pair<int,vector<string>> &gridp1, pair<int,vector<string>> &gridp2) {
        int irrev1 = 0, irrev2 = 0;
        
        for(int i = 1; i < gridp1.second.size()-1; i++) {
            for(int j = 1; j < gridp1.second[1].size()-1; j++) {
                if(gridp1.second[i][j] == gridp1.second[i+1][j] || gridp1.second[i][j] == gridp1.second[i-1][j] || gridp1.second[i][j] == gridp1.second[i][j+1] || gridp1.second[i][j] == gridp1.second[i][j-1]) irrev1++;
                if(gridp2.second[i][j] == gridp2.second[i+1][j] || gridp2.second[i][j] == gridp2.second[i-1][j] || gridp2.second[i][j] == gridp2.second[i][j+1] || gridp2.second[i][j] == gridp2.second[i][j-1]) irrev2++;
            }
        }
    
        return irrev1 < irrev2;
    };
    
    sort(grids.begin(), grids.end(), comp);
    
    cout << grids[0].first << '\n';
    
    vector<string> curr = grids[0].second, ans;
    for(int next = 1; next < k+1; next++) {
        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < m-1; j++) {
                if(curr[i][j] != grids[next].second[i][j]) {
                    curr[i][j] = curr[i][j] == '1' ? '0' : '1';
                    ans.push_back("1 " + to_string(i+1) + " " + to_string(j+1));
                }
            }
        }
    
        ans.push_back("2 " + to_string(grids[next].first));
    }
    
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}