class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) {
            return 0;
        }

        int count = 0;
        long long factor = 1;

        while (n / factor != 0) {
            int curDigit = (n / factor) % 10;
            int highDigits = n / (factor * 10);
            int lowDigits = n % factor;

            if (curDigit == 0) {
                count += highDigits * factor;
            } else if (curDigit == 1) {
                count += highDigits * factor + lowDigits + 1;
            } else {
                count += (highDigits + 1) * factor;
            }

            factor *= 10;
        }

        return count;
    }
};
