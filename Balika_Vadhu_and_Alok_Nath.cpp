#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vvi vector<vector<int>>

const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve()
{
    string s, t;
    int k;
    cin >> s >> t >> k;
    int n = s.length(), m = t.length();

    // dp[i][j][l]: max sum for s[i:], t[j:], length l
    vector<vector<vector<int>>> dp(n + 1, vvi(m + 1, vi(k + 1, -1e12)));

    // Base case: length 0, sum is 0
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j][k] = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            for (int l = 0; l < k; ++l) {
                int ret1 = -1e12;
                if (s[i] == t[j]) {
                    ret1 = dp[i + 1][j + 1][l + 1] + (int)s[i];
                }
                int ret2 = dp[i + 1][j][l];
                int ret3 = dp[i][j + 1][l];
                dp[i][j][l] = max({ret1, ret2, ret3});
            }
        }
    }

    cout << max(dp[0][0][0], 0ll) << "\n";
}

int32_t main()
{
    fastio;

    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}