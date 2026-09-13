class Solution {
public:
    vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        std::stack<int> st;
        std::vector<int> result (temperatures.size(), 0);

        for (int right = 0; right < static_cast<int>(temperatures.size()); ++right) {
            while (!st.empty() && temperatures[right] > temperatures[st.top()]) {

                int left = st.top();
                st.pop();

                result[left] = right - left;
            }
            st.push(right);
        }
        return result;
    }
};
