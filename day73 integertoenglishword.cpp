class Solution {
public:
    std::string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        std::vector<std::string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
                                           "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        std::vector<std::string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        std::vector<std::string> thousands = {"", "Thousand", "Million", "Billion"};

        std::string result = "";
        int groupIndex = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000, below20, tens) + thousands[groupIndex] + " " + result;
            }
            num /= 1000;
            groupIndex++;
        }

        size_t start = result.find_first_not_of(' ');
        size_t end = result.find_last_not_of(' ');
        result = result.substr(start, end - start + 1);

        return result;
    }

private:
    std::string helper(int num, const std::vector<std::string>& below20, const std::vector<std::string>& tens) {
        if (num == 0) {
            return "";
        } else if (num < 20) {
            return below20[num] + " ";
        } else if (num < 100) {
            return tens[num / 10] + " " + helper(num % 10, below20, tens);
        } else {
            return below20[num / 100] + " Hundred " + helper(num % 100, below20, tens);
        }
    }
};
