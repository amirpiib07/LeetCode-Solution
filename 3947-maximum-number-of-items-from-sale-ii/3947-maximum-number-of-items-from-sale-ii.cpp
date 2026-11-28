class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        int cheapest_price = INT_MAX;
        for (auto& vec : items) {
            int f = vec[0];
            int p = vec[1];
            freq[f]++;
            cheapest_price = min(cheapest_price, p);
        }
        vector<int> factorSum(n + 1, 0); 
        for (int f = 1; f <= n; f++) {
            for (int k = f; k <= n; k += f) {
                factorSum[f] += freq[k];
            }
        }

        vector<pair<int, int>> units;
        for (auto& vec : items) {
            int f = vec[0];
            int p = vec[1];

            int cnt = factorSum[f] - 1;          
            
            if (cnt > 0 && p < 2LL * cheapest_price)
                units.push_back({p, cnt});
        }

        sort(begin(units), end(units));

        int result = 0;

        for (auto& [price, factorCount] : units) {
            int k = min(factorCount, budget / price);
            budget -= k * price;
            result += 2 * k; 
        }

        result += budget / cheapest_price; 
        return result;
    }
};