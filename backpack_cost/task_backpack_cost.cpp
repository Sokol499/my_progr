#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, W;
    std::cin >> n >> W;

    std::vector<int> w(n + 1);

    std::vector<int> cost(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> w[i] >> cost[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            if (w[i] <= j)
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i]] + cost[i]);
           
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int w = W; w >= 0; --w)
    {
        if (dp[n][w] != 0)
        {
            std::cout << dp[n][w] << "\n";
            return 0;
        }
    }

    return 1;
}