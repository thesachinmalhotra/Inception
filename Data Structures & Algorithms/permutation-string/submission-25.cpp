class Solution {
   public:
    bool checkInclusion(const std::string& s1, const std::string& s2) {
        if (s1.size() > s2.size()) return false;

        array<int, 26> need{}, window{};

        for (char c : s1) ++need[c - 'a'];

        for (int i = 0; i < s1.size(); ++i) ++window[s2[i] - 'a'];

        for (int left = 0, right = s1.size(); right < s2.size(); ++left, ++right) {
            if (window == need)
                return true;

                --window[s2[left] - 'a'];
                ++window[s2[right] - 'a'];
            }
        return window == need;
    }
};
