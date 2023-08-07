#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

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

struct Cmd {
    ll t, l, r;
};

ll MOD = 1e9 + 7;

void buildSingleTree(vector<ll>& tree, ll v, ll l, ll r) {
    if (l + 1 == r) {
        tree[v] = 1;
        return;
    }

    ll m = (l + r) / 2;
    buildSingleTree(tree, 2 * v + 1, l, m);
    buildSingleTree(tree, 2 * v + 2, m, r);

    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

void push(vector<ll>& tree, vector<ll>& prom, ll v, ll l, ll r) {
    if (prom[v] == 0)
        return;
    tree[v] = (tree[v] + (r - l) * prom[v]) % MOD;
    if (r - l > 1) {
        prom[2 * v + 1] += prom[v];
        prom[2 * v + 2] += prom[v];
    }
    prom[v] = 0; 
}

void update(vector<ll>& tree, vector<ll>& prom, ll v, ll l, ll r, ll sl, ll sr, ll val) {
    push(tree, prom, v, l, r);
    if (r <= sl || sr <= l) 
        return;
    if (sl <= l && r <= sr) {
        prom[v] = (prom[v] + val) % MOD;
        push(tree, prom, v, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    update(tree, prom, 2 * v + 1, l, mid, sl, sr, val);
    update(tree, prom, 2 * v + 2, mid, r, sl, sr, val);
    tree[v] = (tree[2 * v + 1] + tree[2 * v + 2]) % MOD;
}

void printArr(vector<ll>& tree, vector<ll>& prom, ll v, ll l, ll r) {
    push(tree, prom, v, l, r);
    if (l + 1 == r) {
        cout << tree[v] << " ";
        return;
    }
    ll mid = (l + r) / 2;
    printArr(tree, prom, 2 * v + 1, l, mid);
    printArr(tree, prom, 2 * v + 2, mid, r);
}

ll getElem(vector<ll>& tree, vector<ll>& prom, ll v, ll l, ll r, ll ind) {
    push(tree, prom, v, l, r);
    if (l + 1 == r) {
        return tree[v];
    }

    ll mid = (l + r) / 2;
    if (ind < mid) 
        return getElem(tree, prom, 2 * v + 1, l, mid, ind);
    else 
        return getElem(tree, prom, 2 * v + 2, mid, r, ind);
}

void solveCase() {
    ll n, m;
    cin >> n >> m;
    vector<Cmd> a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i].t >> a[i].l >> a[i].r;
        a[i].l -= 1;
        a[i].r -= 1;
    }

    vector<ll> cmdTree(4 * m, 0);
    vector<ll> cmdProm(4 * m, 0);

    buildSingleTree(cmdTree, 0, 0, m);
    //printArr(cmdTree, cmdProm, 0, 0, m);

    vector<ll> arrTree(4 * n, 0);
    vector<ll> arrProm(4 * n, 0);

    for (ll i = m - 1; i >= 0; --i) {
        if (a[i].t == 1) { 
            ll cnt = getElem(cmdTree, cmdProm, 0, 0, m, i);
            //cout << i << " " << a[i].t << " " << a[i].l << " " << a[i].r << " " << cnt << endl;
            update(arrTree, arrProm, 0, 0, n, a[i].l, a[i].r + 1, cnt);
        } else {
            ll cnt = getElem(cmdTree, cmdProm, 0, 0, m, i);
            //cout << i << " " << a[i].t << " " << a[i].l << " " << a[i].r << " " << cnt << endl;
            update(cmdTree, cmdProm, 0, 0, m, a[i].l, a[i].r + 1, cnt);
        }
    }
    printArr(arrTree, arrProm, 0, 0, n);
    cout << endl;
}

void solve() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        solveCase();
    }
}
