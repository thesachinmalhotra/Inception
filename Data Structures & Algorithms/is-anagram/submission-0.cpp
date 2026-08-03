#include <array>
#include <string>

class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
          if(s.size() != t.size()) {
            return false;
          }        

        std::array<int, 26> frequency{};

        for (std::size_t i = 0; i < s.size(); ++i) {
            ++frequency[s[i]- 'a'];
            --frequency[t[i]- 'a'];
        } 
        for (const auto& count: frequency) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};