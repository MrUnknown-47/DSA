class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount + 1, amount + 1);
    minCoins[0] = 0;


    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                minCoins[i] = min(minCoins[i], 1 + minCoins[i - coin]);
            }
        }
    }


    return (minCoins[amount] == amount + 1) ? -1 : minCoins[amount];
    }
};