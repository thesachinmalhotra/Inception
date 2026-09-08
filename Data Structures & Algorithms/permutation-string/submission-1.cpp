class Solution {
   public:
    bool checkInclusion(const std::string& s1, const std::string& s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        std::array<int, 26> target{};
        std::array<int, 26> window{};

        for (const char c : s1) {
            ++target[c - 'a'];
        }

        for (int i = 0; i < static_cast<int>(s1.size()); ++i) {
            ++window[s2[i] - 'a'];
        }

        int left = 0;

        for (int right = static_cast<int>(s1.size()); right < static_cast<int>(s2.size());
             ++right) {
            if (window == target) {
                return true;
            }
            --window[s2[left] - 'a'];
            ++window[s2[right] - 'a'];
            ++left;
        }
        return window == target;
    }
};
