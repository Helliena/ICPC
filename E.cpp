#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define f first
#define s second

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

void caseSol() {
    ll n;
    cin >> n;
    vector<pll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].f;
        a[i].s = i; 
    }
    sort(a.begin(), a.end());
    vector<ll> ans(n, 0);

    ll sum = 0;
    for (ll i = n - 1; i >= 0; --i) {
        sum += a[i].f - a[0].f + 1; 
    }

    ans[a[0].s] = sum;
    for (ll i = 1; i < n - 1; ++i) {
        ans[a[i].s] = sum - (n - i - 1) * (a[i].f - a[i - 1].f) + (i - 1) * (a[i].f - a[i - 1].f);
        sum = ans[a[i].s];
    }

    sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += a[n - 1].f - a[i].f + 1;
    }
    ans[a[n - 1].s] = sum;

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

void solve() {
    ll t;
    cin  >> t;
    for (ll i = 0; i < t; ++i) {
        caseSol();
    }
    
}
