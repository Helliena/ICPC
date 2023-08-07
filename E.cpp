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
    cout << setprecision(2);
}

int main() {
    acceleration();
    //precision();
    solve();
}


void solve() {
   ll n;
   cin >> n;
   vector<ll> a(n, 0);
   for (ll i = 0; i < n; ++i) {
        cin >> a[i];
   }

   vector<ll> minSum(n + 1, INF);
   vector<vector<pll>> dp(n + 1, vector<pll>(20, {INF, INF}));

   dp[0][0] = {a[0], a[0]};
   minSum[0] = a[0];
   for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= 19; ++j) {
            if (j == 0) {
                dp[i][j].f = minSum[i - 1] + a[i];
                dp[i][j].s = a[i];
            } else {
                dp[i][j].f = dp[i - 1][j - 1].f + a[i];
                dp[i][j].s = min(dp[i - 1][j - 1].s, a[i]);
            }
        
            minSum[i] = min(minSum[i], dp[i][j].f - (j >= 9 ? dp[i][j].s : 0));
        }
   }
   cout << minSum[n - 1] << endl;
}
