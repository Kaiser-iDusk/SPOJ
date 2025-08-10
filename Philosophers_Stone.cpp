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
    int h, w;
    cin >> h >> w;
    vvi grid(h, vi(w, 0));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];
    }
    int dr[3] = {1, 1, 1}, dc[3] = {-1, 0, 1};
    vvi dp(h + 1, vi(w + 1, 0));
    for (int i = 0; i < w; i++)
    {
        dp[0][i] = grid[0][i];
    }
    for (int i = 1; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int pr = i - dr[k], pc = j - dc[k];
                if (pc < 0 || pc >= w)
                    continue;
                dp[i][j] = max(dp[i][j], dp[pr][pc] + grid[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < w; i++)
        ans = max(ans, dp[h - 1][i]);
    cout << ans << "\n";
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