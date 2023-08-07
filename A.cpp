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

ll getLength(ll n) {
    ll ans = 0;
    while (n > 0) {
        ans += 1;
        n /= 10;
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    if (n < 10) {
        cout << 2 << endl;
        return;
    }

    ll ans = 0;
    ll cnt = 2;
    for (ll i = 10; i <= 1e12; i *= 10) {
        ans += cnt * ((min(n, i * 10 - 10) - i) / 10 + 1);
        cnt += 1;

        if (n < i * 10)
           break;
    }

    cout << ans + 1 + (n % 10 ? 1 * getLength(n) : 0) << endl;
   
}
