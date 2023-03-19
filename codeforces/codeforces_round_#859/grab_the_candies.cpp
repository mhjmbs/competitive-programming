#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int &ai : a) cin >> ai;

        auto comp = [](int a, int b) {
            if(a % 2 == 0) {
                if(b % 2 == 0) return a < b;
                return true;;
            }else if(b % 2 == 0){
                return false;
            }else {
                return a < b;
            }
        };

        sort(a.begin(), a.end(), comp);

        int mihai = 0, bianca = 0;
        bool possible = true;

        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0) mihai += a[i];
            else bianca += a[i];

            if(mihai <= bianca) possible = false;
        }

        if(possible) cout << "YES\n";
        else cout << "NO\n";
    }
}