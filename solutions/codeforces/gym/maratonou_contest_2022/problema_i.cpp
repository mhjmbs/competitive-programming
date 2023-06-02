#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n+1);

        for(int i = 1; i < n+1; i++) {
            cin >> p[i];
        }

        int components = 0, maxNumber = 0;
        set<int> maxNumbers;

        for(int i = 1; i < n+1; i++) {
            components++;
            if(p[i] > maxNumber) {
                maxNumber = p[i];
                maxNumbers.insert(p[i]);
            }else {
                int currMaxNumber = 0;
                stack<int> toRemove;
                maxNumbers.insert(p[i]);
                toRemove.push(p[i]);
                for(auto it = maxNumbers.rbegin(); *it != p[i]; it++) {
                    currMaxNumber = max(currMaxNumber, *it);
                    toRemove.push(*it);
                }

                while(!toRemove.empty()) {
                    maxNumbers.erase(toRemove.top());
                    toRemove.pop();
                    components--;
                }
                maxNumbers.insert(currMaxNumber);
                components++;
            }
        }

        cout << components << '\n';
    }
}