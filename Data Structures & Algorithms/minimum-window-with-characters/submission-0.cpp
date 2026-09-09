class Solution {
public:
    std::string minWindow(const std::string& s, const std::string& t) {
        if (t.size() > s.size()) {
            return "";
        }

        std::array<int, 128> need{};
        std::array<int, 128> window{};

        int required = 0;

        for (const char c : t) {
            if (need[c] == 0) {
                ++required;
            }
            ++need[c];
        }

        int formed = 0;
        int left = 0;
        int minLength = INT_MAX;
        int resultStart = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            const char c = s[right];
            ++window[c];

            if (window[c] == need[c]) {
                ++formed;
            }

            while (formed == required) {
                const int currentLength = right - left + 1;

                if (currentLength < minLength) {
                    minLength = currentLength;
                    resultStart = left;
                }

                const char leftChar = s[left];
                --window[leftChar];

                if (window[leftChar] < need[leftChar]) {
                    --formed;
                }

                ++left;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(resultStart, minLength);
    }
};