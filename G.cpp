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

void solve() {
    string a, b;
    cin >> a >> b;
    if (a != b) {
        cout << 1 << endl;
    } else {
        cout << a << endl;
    }
}
