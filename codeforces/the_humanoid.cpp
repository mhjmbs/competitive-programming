#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;
using ll = long long;

ll test(int currA, ll h, int ans, vector<int>& a, queue<int>& s) {

    while(currA != a.size() && (!s.empty() || h > a[currA])) {
        if(h <= a[currA]) {
            h *= s.front();
            s.pop();
        }else {
            ans++;
            h += a[currA]/2;
            currA++;
        }
    }

    while(!s.empty()) s.pop();

    return ans;
}

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        ll h;
        cin >> n >> h;

        vector<int> a(n);

        for(int& ai : a) cin >> ai;

        sort(a.begin(), a.end());

        int currA = 0, ans = 0;

        while(currA != a.size() && h > a[currA]) {
            h += a[currA]/2;
            currA++;
            ans++;
        }

        if(currA == a.size()) {
            cout << ans << '\n';
            continue;
        }

        ll finalAns = ans;
        queue<int> q;
        q.push(2);
        q.push(2);
        q.push(3);

        finalAns = max(finalAns,test(currA, h, ans, a, q));

        q.push(2);
        q.push(3);
        q.push(2);
        finalAns = max(finalAns,test(currA, h, ans, a, q));

        q.push(3);
        q.push(2);
        q.push(2);
        finalAns = max(finalAns,test(currA, h, ans, a, q));

        cout << finalAns << '\n';
    }
}