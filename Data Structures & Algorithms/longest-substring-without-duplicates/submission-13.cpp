class Solution {
public:
    int lengthOfLongestSubstring(std::string& s) {
        std::unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < static_cast<int> (s.size()); ++right) {
            const char character = s[right];

            if (lastSeen.find(character) != lastSeen.end()) {
                left = std::max(lastSeen[character] + 1, left);
            }
            lastSeen[character] = right;

            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
