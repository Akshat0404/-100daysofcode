class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        int n = words.size();
        std::vector<int> wordBits(n);

        for (int i = 0; i < n; ++i) {
            int bitRepresentation = 0;
            for (char c : words[i]) {
                bitRepresentation |= (1 << (c - 'a'));
            }
            wordBits[i] = bitRepresentation;
        }

        int maxProduct = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((wordBits[i] & wordBits[j]) == 0) {
                    int product = words[i].length() * words[j].length();
                    maxProduct = std::max(maxProduct, product);
                }
            }
        }

        return maxProduct;
    }
};
