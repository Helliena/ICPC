#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define f first
#define s second

ll const INF = 1e18;
ll const MOD = 998244353;

void acceleration(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();

int main() {
    acceleration();
    solve();
}

ll binPow(ll a, ll n) {
    //cout << a << " " << n << endl;
    if (n == 0)
        return 1;
    
    if (n % 2) 
        return (a * binPow(a, n - 1)) % MOD;
    else {
        ll x = binPow(a, n / 2);
        return (x * x) % MOD;
    }
}

pll getCap(vector<pll>& p, ll v) {
    if (v == p[v].f) 
        return {v, p[v].s};
    
    pll tmp = getCap(p, p[v].f);
    p[v].f = tmp.f;
    return tmp;
}

void dsuUnite(vector<pll>& p, ll a, ll b) {
    pll x = getCap(p, a);
    pll y = getCap(p, b);

    if (rand() & 1)
        swap(x, y);

    if (x != y) {
        p[x.f].f = y.f;
        p[y.f].s += p[x.f].s; 
    } 
}

ll calcSpanningTree(vector<pair<ll, pll>>& g, ll n, ll s) {
    ll ans = 1;
    sort(g.begin(), g.end());
    
    vector<pll> p(n);
    for (ll i = 0; i < n; ++i) {
        p[i] = {i, 1};
    }

    for (int i = 0; i < n - 1; ++i) {
        ll a = g[i].s.f, b = g[i].s.s, c = g[i].f;
        //cout << a << " " << b << " " << c << " ";
        ll t1 = getCap(p, a).s;
        ll t2 = getCap(p, b).s;
        //cout << t1 << " " << t2 << endl;
        ans = (ans * binPow(1 + s - c, t1 * t2 - 1)) % MOD;
        dsuUnite(p, a, b);
    }



    return ans;
}

void caseSol() {
    ll n, s;
    cin >> n >> s;
    vector<pair<ll, pll>> g(n - 1);
    ll u, v, w;
    for (ll i = 0; i < n - 1; ++i) {
        cin >> g[i].s.f >> g[i].s.s >> g[i].f;
        --g[i].s.f, --g[i].s.s;
    } 
    cout << calcSpanningTree(g, n, s) << endl;
}

void solve() {
    ll t;
    cin  >> t;
    for (ll i = 0; i < t; ++i) {
        caseSol();
    }
}
