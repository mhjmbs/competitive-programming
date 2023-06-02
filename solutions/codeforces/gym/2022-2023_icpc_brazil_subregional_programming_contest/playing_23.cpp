#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;

int points(int card) {
    if(card < 10) {
        return card;
    }else {
        return 10;
    }
}

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> cards(14, 4);

    int j = 0, m = 0;

    for(int i = 0, card; i < 2; i++) {
        cin >> card;
        j += points(card);
        cards[card]--;
    }

    for(int i = 0, card; i < 2; i++) {
        cin >> card;
        m += points(card);
        cards[card]--;
    }

    for(int i = 0, card; i < n; i++) {
        cin >> card;
        j += points(card);
        m += points(card);
        cards[card]--;
    }

    int ans = -1;

    for(int card = 1; card < 14; card++) {
        if(cards[card] == 0) {
            continue;
        }

        int nj = j+points(card);
        int nm = m+points(card);

        if(nm == 23 || (nj > 23 && nm <=23)) {
            ans = card;
            break;
        }
    }

    cout << ans << '\n';
}
