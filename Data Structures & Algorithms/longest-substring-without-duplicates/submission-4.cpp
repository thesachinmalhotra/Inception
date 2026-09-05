class Solution {
   public:
    int lengthOfLongestSubstring(std::string& s) {
        std::array<int, 128> lastSeen;
        lastSeen.fill(-1);

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            const char character = s[right];

        if (lastSeen[character] >= left) {
                left = lastSeen[character] + 1;
            }

            lastSeen[character] = right;

            const int currentLength = right - left + 1;
            maxLength = std::max(maxLength, currentLength);
        }
        return maxLength;
    }
};
