class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        std::vector<long long> uglyNumbers(n, LLONG_MAX);
        std::vector<int> indices(primes.size(), 0);

        uglyNumbers[0] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < primes.size(); ++j) {
                uglyNumbers[i] = std::min(uglyNumbers[i], uglyNumbers[indices[j]] * primes[j]);
            }

            for (int j = 0; j < primes.size(); ++j) {
                if (uglyNumbers[i] == uglyNumbers[indices[j]] * primes[j]) {
                    indices[j]++;
                }
            }
        }

        return static_cast<int>(uglyNumbers[n - 1]);
    }
};
