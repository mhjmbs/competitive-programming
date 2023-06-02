#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    ll n, p, h;
    cin >> n >> p >> h;

    ll curr_h = h, max_h = 1ll<<n;
    stack<bool> s;

    while(max_h != 1) {
        if(curr_h > max_h/2) {
            s.push(true);
            curr_h = max_h - (curr_h-1);
            max_h /= 2;        
        }else {
            s.push(false);
            max_h /= 2;
        }
    }

    string ans;

    ll curr_x = p, max_x = 1ll<<n;

    while(max_x != 1) {
        bool up = s.top();
        s.pop();

        if(up) {
            if(curr_x > max_x/2) {
                ans.push_back('R');
                curr_x = max_x - (curr_x-1);
                max_x /= 2;
            }else {
                ans.push_back('L');
                curr_x = max_x/2 - (curr_x-1);
                max_x /= 2;
            }
        }else {
            if(curr_x > max_x/2) {
                ans.push_back('L');
                curr_x = curr_x - max_x/2;
                max_x /= 2;
            }else {
                ans.push_back('R');
                max_x /= 2;
            }
        }
    }

    cout << ans << '\n';
}