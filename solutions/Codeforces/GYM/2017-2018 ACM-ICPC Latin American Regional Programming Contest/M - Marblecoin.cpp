#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;

const ll p = 307, mod = 1e9+7;
vector<ll> invModPow, pPow;
vector<vector<ll>> stacks;
priority_queue<pll, vector<pll>, greater<pll>> prioq;

tlll egcd(const ll a, const ll b) {
    if(b == 0) {
        return {a, 1ll, 0ll};
    }else {
        auto [gcd, x, y] = egcd(b, a%b);
        return {gcd, y, x-(a/b)*y};
    }
}

ll posMod(ll a, ll m) {
    return (a % m + m) % m;
}

vector<ll> enhash(const vector<ll> &v) {
    vector<ll> hash(v.size()+1, 0);

    for(ll i = 1; i < hash.size(); i++) {
        hash[i] = posMod(hash[i-1] + v[i-1] * pPow[i-1], mod);
    }

    return hash;
}

ll getHash(const vector<ll> &hash, const ll l, const ll r) {
    return posMod(posMod(hash[r+1] - hash[l], mod) * invModPow[l], mod);
}

void stackMerge(const vector<ll> &a, const vector<ll> &b) {
    const vector<ll> hashA = enhash(a);
    const vector<ll> hashB = enhash(b);

    ll i = 0, j = 0;

    while(i < a.size() && j < b.size()) {
        const ll maxSize = min(a.size()-i, b.size()-j);
        ll l = 1, r = maxSize, bestSZ = -1;

        while(l <= r) {
            const ll sz = (l+r)/2;
            if(getHash(hashA, i, i+sz-1) != getHash(hashB, j, j+sz-1)) {
                bestSZ = sz;
                r = sz-1;
            }else {
                l = sz+1;
            }
        }
        
        if(bestSZ == -1 && a.size()-i <= b.size()-j) {
            stacks.back().push_back(b[j]);
            j++;
        }else if(bestSZ == -1 && a.size()-i > b.size()-j) {
            stacks.back().push_back(a[i]);
            i++;
        }else if(a[i+bestSZ-1] < b[j+bestSZ-1]) {
            stacks.back().push_back(a[i]);
            i++;
        }else {
            stacks.back().push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()) {
        stacks.back().push_back(a[i]);
        i++;
    }
    while(j < b.size()) {
        stacks.back().push_back(b[j]);
        j++;
    }

    prioq.emplace(stacks.back().size(), stacks.size()-1);
}

void computePowers(const ll kSum) {
    pPow.resize(kSum+1);
    invModPow.resize(kSum+1);
    
    pPow[0] = 1;
    pPow[1] = p;
    invModPow[0] = 1;
    invModPow[1] = get<1>(egcd(p, mod));

    for(ll i = 2; i < kSum+1; i++) {
        pPow[i] = posMod(pPow[i-1] * p, mod);
        invModPow[i] = posMod(invModPow[i-1] * invModPow[1], mod);
    }
}

int main() {
    fastio;

    ll n, kSum = 0;
    cin >> n;

    stacks.resize(n);

    for(ll i = 0, k; i < n; i++) {
        cin >> k;
        kSum += k;

        stacks[i].resize(k);
        for(ll &ki : stacks[i]) cin >> ki;
        prioq.emplace(k, i);
    }

    computePowers(kSum);

    while(prioq.size() > 1) {
        const ll i1 = prioq.top().second;
        prioq.pop();
        const ll i2 = prioq.top().second;
        prioq.pop();

        stacks.push_back({});
        stackMerge(stacks[i1],stacks[i2]);
    }

    ll ans = 0;

    ll pow365 = 365;
    for(ll i = kSum-1; i >= 0; i--) {
        ans = posMod(ans + stacks.back()[i] * pow365, mod);
        pow365 = posMod(pow365 * 365, mod);
    }

    cout << ans << '\n';
}