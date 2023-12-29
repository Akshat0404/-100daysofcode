class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }

        std::sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });

        std::vector<int> heights;
        for (const auto& envelope : envelopes) {
            auto it = std::lower_bound(heights.begin(), heights.end(), envelope[1]);
            if (it == heights.end()) {
                heights.push_back(envelope[1]);
            } else {
                *it = envelope[1];
            }
        }

        return heights.size();
    }
};
