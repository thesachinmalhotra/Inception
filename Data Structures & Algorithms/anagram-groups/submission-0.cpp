class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& word : strs) {
           std::string key{word};
           std::ranges::sort(key);

           groups[key].push_back(word);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(groups.size());

        for (auto& [_, group] : groups) {
            result.push_back(std::move(group));
        }
        return result;
    }
};
