#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    if(n <= 3) {
        if(n == 1) cout << "1\n";
        else cout << "NO SOLUTION\n";
        return 0;
    }

    deque<int> dq = {2,4,1,3};

    bool left = true;
    for(int i = 5; i <= n; i++) {
        if(left) dq.push_front(i);
        else dq.push_back(i);
        left = !left;
    }

    while(!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
        if(dq.size() == 0) cout << '\n';
        else cout << ' ';
    }
    
}