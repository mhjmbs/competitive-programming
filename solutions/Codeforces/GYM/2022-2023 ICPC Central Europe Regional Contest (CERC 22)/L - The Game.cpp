#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int>> rows = {{1},{1},{100},{100}};
vector<int> hand, deck;

void drawCard() {
    hand.push_back(deck.back());
    deck.pop_back();
}

void playCard(int card, int row) {
    rows[row].push_back(hand[card]);
    hand.erase(hand.begin() + card);
}

bool playTurn() {
    pii backward = {-1,-1}, regular = {-1,-1};
    int minDiff = INT_MAX;

    for(int i = hand.size()-1; i >= 0; i--) {
        for(int j = 3; j >= 2; j--) {
            if(hand[i] - rows[j].back() == 10) backward = {i,j};
            if(rows[j].back() - hand[i] <= minDiff && rows[j].back() > hand[i]) regular = {i,j}, minDiff = rows[j].back() - hand[i];
        }
        for(int j = 1; j >= 0; j--) {
            if(rows[j].back() - hand[i] == 10) backward = {i,j};
            if(hand[i] - rows[j].back() <= minDiff && hand[i] > rows[j].back()) regular = {i,j}, minDiff = hand[i] - rows[j].back();
        }
    }

    if(backward != make_pair(-1,-1)) {
        playCard(backward.first, backward.second);
        return false;
    }

    if(regular != make_pair(-1,-1)) {
        playCard(regular.first, regular.second);
        return false;
    }

    return true;
}

int main() {
    fastio;
    
    for(int i = 0; i < 98; i++) {
        int card;
        cin >> card;
        deck.push_back(card);
    }

    reverse(deck.begin(), deck.end());

    while(hand.size() < 8) drawCard();

    bool lost = false;

    while(!hand.empty()) {

        lost = playTurn();
        lost = playTurn();

        if(lost) break;

        if(!deck.empty()) drawCard();
        if(!deck.empty()) drawCard();
    }

    for(auto row : rows) {
        for(int card : row) cout << card << ' ';
        cout << '\n';
    }

    for(int card : hand) cout << card << ' ';
    cout << '\n';

    for(int i = deck.size()-1; i >= 0; i--) cout << deck[i] << ' ';
    cout << '\n';
}