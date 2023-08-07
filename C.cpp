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

vector<vector<ll>> transp(const vector<vector<ll>>& a) {
    vector<vector<ll>> res(a[0].size(), vector<ll>(a.size(), 0));
    for (ll i = 0; i < a[0].size(); ++i) {
        for (ll j = 0; j < a.size(); ++j) {
            res[i][j] = a[j][i];
        }
    }
    return res;
}

void print(const vector<vector<ll>>& res) {
    for (ll i = 0; i < res.size(); ++i) {
        for (ll j = 0; j < res[0].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<ll>> mult(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
    ll mod = 1e9 + 7;
    vector<vector<ll>> res(a.size(), vector<ll>(b[0].size(), 0));
    for (ll i = 0; i < a.size(); ++i) {
        for (ll j = 0; j < b[0].size(); ++j) {
            for (ll k = 0; k < a[0].size(); ++k) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> binPow(const vector<vector<ll>>& a, ll n) {
    if (n == 1) {
        return a;
    }

    if (n % 2) {
        return mult(binPow(a, n - 1), a);
    } else {
        vector<vector<ll>> tmp = binPow(a, n / 2);
        return mult(tmp, tmp);
    }
}

void solve() {
    ll w;
    cin >> w;

    if (w == 2) {
        cout << 4 << endl;
        return;
    } else if (w == 3) {
        cout << 13 << endl;
        return;
    }

    ll n = 13;
    vector<vector<ll>> base(1, vector<ll>(n));
    base  = {{1, 1, 1, 1, 3, 2, 3, 3, 3, 3, 9, 6, 13}};

    vector<vector<ll>> trans(n, vector<ll>(n));
    trans = {{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
             {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 2, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
             {1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
             {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
             {0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
             {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
             {0, 2, 1, 2, 1, 1, 0, 2, 1, 2, 1, 1, 0},
             {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
             {0, 2, 1, 2, 1, 1, 0, 2, 1, 2, 1, 1, 1}};

    trans = transp(trans);

    vector<vector<ll>> res = mult(base, binPow(trans, w - 3));
    
    cout << res[0][12] << endl;
}
