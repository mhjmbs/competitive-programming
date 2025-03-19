#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n, p, h;
    cin >> n >> p >> h;
    
    vector<ll> sums, mult;
    int atk = 0;
    
    for(int i = 0; i < n; i++) {
        char type;
        cin >> type;
        
        if(type == '!') {
            atk++;
        }else if(type == '*') {
            ll x;
            cin >> x;
            mult.push_back(x);
        }else {
            ll y;
            cin >> y;
            sums.push_back(y);
        }
    }
    
    sort(sums.rbegin(), sums.rend());
    sort(mult.rbegin(), mult.rend());

    if(atk == 0 || p == 0 && sums.empty()) {
        cout << "*\n";
        return 0;
    }

    if(atk == n) {
        ll ans = (h+p-1)/p;
        cout << ans << '\n';
        return 0;
    }
    
    ll cards = 0;

    if(sums.empty() && count(mult.begin(), mult.end(), 1) == mult.size()) {
        ll dmg = (h+p-1)/p;
        ll turns = (dmg+atk-1)/atk - 1;
        cards = turns*n;
        h -= turns*atk*p;
    }

    while(true) {
        ll np = p;

        bool overflow = false;

        for(ll x : sums) np += x;
        for(ll y : mult) {
            if(np > LONG_LONG_MAX/y) overflow = true;
            np *= y;
        }

        overflow = overflow || np > LONG_LONG_MAX/atk;

        if(overflow || h-np*atk <= 0) {
            break;
        }

        p = np;
        h -= p*atk;
        cards += n;
    }

    ll ans = 1e18;

    for(int sums_count = 0; sums_count <= sums.size(); sums_count++) {
        for(int mult_count = 0; mult_count <= mult.size(); mult_count++) {
            for(int atk_count = 1; atk_count <= atk; atk_count++) {
                ll np = p;

                for(int i = 0; i < sums_count; i++) {
                    np += sums[i];
                }

                bool overflow = false;

                for(int i = 0; i < mult_count; i++) {
                    if(np > LONG_LONG_MAX/mult[i]) overflow = true;
                    np *= mult[i];
                }

                if(np > LONG_LONG_MAX/atk_count) overflow = true;

                if(overflow || h-np*atk_count <= 0) {
                    ans = min(ans, cards+sums_count+mult_count+atk_count);
                }
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}