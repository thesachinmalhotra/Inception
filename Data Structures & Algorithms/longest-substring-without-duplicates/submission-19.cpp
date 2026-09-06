class Solution {
public:
    int lengthOfLongestSubstring(std::string& s) {
        std::array<int, 128> lastSeen;
        lastSeen.fill(-1);

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char character = s[right];

            if (lastSeen[character] >= left) {
                left = lastSeen[character] + 1;
            }
            
            lastSeen[character] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
