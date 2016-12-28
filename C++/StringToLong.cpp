class Solution {
public:
    long stringToLong(string s) {
        try {
            int size = (int)s.size();
            if (size == 0) throw invalid_argument("String s represents an invalid number.");
            long ans = 0;
            bool isNegative = false;
            int i = 0;
            if (s[i] == '+') {
                ++i;
            } else if (s[i] == '-') {
                isNegative = true;
                ++i;
            }
            if ((size - i == 0) || (s[i] == '0' && size - i != 1)) {
                throw invalid_argument("String s represents an invalid number.");
            }
            for (; i < size; ++i) {
                if (isdigit(s[i])) {
                    int digit = s[i] - '0';
                    if (isNegative) {
                        if (ans > LONG_MAX/10 || (ans == LONG_MAX/10 && digit > 8)) {
                            throw invalid_argument("String s represents an overflow number.");
                        } else {
                            ans *= 10;
                            ans += digit;
                        }
                    } else {
                        if (ans > LONG_MAX/10 || (ans == LONG_MAX/10 && digit > 7)) {
                            throw invalid_argument("String s represents an overflow number.");
                        } else {
                            ans *= 10;
                            ans += digit;
                        }
                    }
                } else {
                    throw invalid_argument("String s represents an invalid number.");
                }
            }
            return isNegative ? -ans : ans;
        } catch (exception& e) {
            cout << e.what() << endl;
            return -1;
        }
    }
};