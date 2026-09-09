class Solution {
public:
    string minWindow(const string& s, const string& t) {
        if (t.empty() || t.size() > s.size())
            return "";

        array<int, 128> need{};
        array<int, 128> window{};

        int required = 0;

        for (unsigned char c : t) {
            if (need[c]++ == 0)
                ++required;
        }

        int formed = 0;
        int left = 0;

        int bestStart = 0;
        int bestLength = INT_MAX;

        for (int right = 0; right < s.size(); ++right) {
            unsigned char c = s[right];

            if (++window[c] == need[c])
                ++formed;

            while (formed == required) {
                int length = right - left + 1;

                if (length < bestLength) {
                    bestLength = length;
                    bestStart = left;
                }

                unsigned char leftChar = s[left];

                if (--window[leftChar] < need[leftChar])
                    --formed;

                ++left;
            }
        }

        return bestLength == INT_MAX
            ? ""
            : s.substr(bestStart, bestLength);
    }
};