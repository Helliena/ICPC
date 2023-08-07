#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define x first
#define y second

void acceleration(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();

void precision() {
    cout << fixed;
    cout << setprecision(2);
}

int main() {
    //acceleration();
    precision();
    solve();
}

bool intersect(ll a, ll b, ll c, ll d) {
    if (a > b)  
        swap (a, b);
	if (c > d)  
        swap (c, d);
	return max(a,c) <= min(b,d);
}

ll area(pll a, pll b, pll c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dist(pll a, pll b) {
    double dist = sqrt(static_cast<double>((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
    return dist;
}

void solve() {
    pll a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    if (intersect(a.x, b.x, c.x, d.x) && intersect(a.y, b.y, c.y, d.y) &&
        area(a, b, c) * area(a, b, d) <= 0 && area(c, d, a) * area(c, d, b) <= 0) {
        cout << min(dist(a, c) + dist(c, b), dist(a, d) + dist(d, b)) << endl;
    } else {
        cout << dist(a, b) << endl;
    }
}
