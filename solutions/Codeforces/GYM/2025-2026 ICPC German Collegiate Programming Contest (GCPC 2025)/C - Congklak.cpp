#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

void play_to_pos(ll cnt, vector<ll>& a, ll pos) {
    int n = a.size();

    for(int i = 0, p = 0; p < pos; i++, p += 2) {
        ll ncnt = a[p] ? (cnt+1)/2 : cnt/2;
        a[p] = a[p] ? (cnt+1)%2 : cnt%2;
        if(p+1 < n) a[p+1] += ncnt;
        cnt = ncnt;
    }
}

void play_game(vector<ll>& a) {
    int n = a.size();
    ll hand = 1;

    for(int i = 0; i < n; i++) {
        a[i]++;
        hand--;
        if(a[i] == 1 && hand == 0) {
            break;
        }else if(a[i] != 1 && hand == 0){
            swap(hand, a[i]);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;

    ll game = 0, pos = 0;

    for(; pos < n; pos += 2) {
        ll num = 0;
        for(int i = pos-1; i >= 0; i--) {
            if(i%2 == 0) {
                num <<= 1;
                num += a[i];
            }
        }

        ll cnt = (1ll<<(pos/2))-num;
        if(t-game <= cnt-1) break;
        play_to_pos(cnt-1, a, pos);
        play_game(a);
        game += cnt;
    }

    play_to_pos(t-game, a, pos);

    for(ll ai : a) cout << ai << ' ';
    cout << '\n';

    return 0;
}