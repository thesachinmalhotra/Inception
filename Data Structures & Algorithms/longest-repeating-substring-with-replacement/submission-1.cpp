class Solution {
public:
    int characterReplacement(const std::string& s, int k) {
        std::array<int, 26> frequency{};

        int left = 0;
        int maxLength = 0;
        int maxFrequency = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right){
            const int index = s[right] - 'A';
            ++frequency[index];

            maxFrequency = std::max(maxFrequency, frequency[index]);

            while (right - left + 1 - maxFrequency > k) {
                --frequency[s[left] - 'A'];
                ++left;
            }
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
