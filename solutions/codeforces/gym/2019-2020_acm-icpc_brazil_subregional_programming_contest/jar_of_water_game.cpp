#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

vector<string> hands;
bool just_recieved;

map<char,int> value = {
    {'0',0},
    {'1',1},
    {'2',2},
    {'3',3},
    {'4',4},
    {'5',5},
    {'6',6},
    {'7',7},
    {'8',8},
    {'9',9},
    {'D',10},
    {'Q',11},
    {'J',12},
    {'K',13}
};

bool won(int curr) {
    for(int j = 1; j < hands[curr].size(); j++) {
        if(hands[curr][0] != hands[curr][j]) return false;
    }
    return true;
}

bool has_wild(int curr) {
    for(int j = 1; j < hands[curr].size(); j++) {
        if(hands[curr][j] == 'W') return true;
    }
    return false;
}

void pass_card(int curr, int next) {
    map<char,int> card_occur;

    for(char card : hands[curr]) {
        if(card == 'W') continue;
        card_occur[card]++;
    }

    char best_card = 'K';
    int min_occur = INT_MAX;

    for(auto x : card_occur) {
        auto [card,occur] = x;

        if(occur == min_occur) {
            if(value[card] < value[best_card]) best_card = card;
        }else if(occur < min_occur) {
            best_card = card;
            min_occur = occur;
        }
    }

    hands[curr].erase(hands[curr].find(best_card), 1);
    hands[next].push_back(best_card);
}

int main(){
    fastio;
    
    int n, k;
    cin >> n >> k;

    hands.resize(n);

    for(string &hand : hands) cin >> hand;

    int curr = k-1;
    hands[curr].push_back('W');
    just_recieved = true;

    int winner = -1;
    char winning_card;

    for(int i = 0; i < n; i++) {
        if(won(i)) {
            if(winner == -1 || value[hands[i][0]] < value[winning_card]) {
                winner = i;
                winning_card = hands[i][0];
            }
        }
    }

    if(winner != -1) {
        cout << winner+1 << '\n';
        return 0;
    }

    while(true) {
        int next = (curr+1)%n;

        if(has_wild(curr)) {
            if(just_recieved) {
                pass_card(curr, next);
                just_recieved = false;
            }else {
                hands[curr].erase(hands[curr].find('W'), 1);
                hands[next].push_back('W');
                just_recieved = true;
            }
        }else {
            pass_card(curr, next);
        }

        if(won(curr)) {
            cout << curr+1 << endl;
            return 0;
        }

        curr = next;
    }

    return 0;
}