class Solution {
public:
    bool isAdditiveNumber(std::string num) {
        int n = num.length();

        for (int i = 1; i <= n / 2; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::string num1 = num.substr(0, i);
                std::string num2 = num.substr(i, j - i);

                if ((num1.length() > 1 && num1[0] == '0') || (num2.length() > 1 && num2[0] == '0')) {
                    continue;
                }

                long long a = std::stoll(num1);
                long long b = std::stoll(num2);

                if (isValidAdditive(num, a, b, j)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool isValidAdditive(const std::string& num, long long a, long long b, int start) {
        int n = num.length();

        while (start < n) {
            long long sum = a + b;
            std::string sumStr = std::to_string(sum);
            int len = sumStr.length();

            if (start + len > n || num.substr(start, len) != sumStr) {
                return false;
            }

            start += len;
            a = b;
            b = sum;
        }

        return true;
    }
};
