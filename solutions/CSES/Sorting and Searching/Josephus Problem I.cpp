#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<bool> taken(n+1, 0);
    int count = 0, child = 1;
    bool take_next = false;

    while(count < n) {
        if(child == n+1) child = 1;
        if(!taken[child]) {
            if(take_next) {
                taken[child] = true;
                take_next = false;
                count++;

                cout << child;
                if(count != n) cout << ' ';
                else cout << '\n';
            }else {
                take_next = true;
            }
        }
        child++;
    }
}