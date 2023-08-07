#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define f first
#define s second

const ll INF = 1e18;

void acceleration(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();

void precision() {
    cout << fixed;
    cout << setprecision(4);
}

int main() {
    //acceleration();
    precision();
    solve();
}

double f(ll i, ll d, double p, ll n, ll k, double a, double b, double c) {
    if (i == n + 1 || abs(d) == k) {
        return p * static_cast<double>(i - 1);
    }
    return f(i + 1, d + 1, p * a / (a + b + c), n, k, a, b, c) +
           f(i + 1, d - 1, p * b / (a + b + c), n, k, a, b, c) +
           f(i + 1, d,     p * c / (a + b + c), n, k, a, b, c); 

    

}

void solve() {
    double a, b, c;
    ll n, k;
    cin >> a >> b >> c >> n >> k;
    cout << f(1, 0, 1, n, k, a, b, c);
}
