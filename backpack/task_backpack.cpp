#include <iostream>
#include <vector>

int main()
{
    int n, W;
    std::cin >> n >> W;

    std::vector<int> w(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> w[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int> (W + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            if (w[i] <= j)
            {
                dp[i][j] = static_cast<int>(static_cast<bool>(dp[i - 1][j]) || static_cast<bool>(dp[i - 1][j - w[i]]));
                // (int)(...) C-style cast
                // reinterpret_cast<int>
                // const_cast<const int>
                // static_cast<int> - кастование типов  проверкой
                // dynamic_cast<> - виртуальные функции и классы

            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int w = W; w >= 0; --w)
    {
        if (dp[n][w] == 1)
        {
            std::cout << w << "\n";
            return 0;
        }
    }
}