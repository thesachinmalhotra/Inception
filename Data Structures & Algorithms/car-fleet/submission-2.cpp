class Solution {
   public:
    int carFleet(int target, const std::vector<int>& position, const std::vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;

        for (int i = 0; i < position.size(); ++i) cars.push_back({position[i], speed[i]});

        std::sort(cars.begin(), cars.end(),
                  [](const auto& a, const auto& b) { return a.first > b.first; });
        int fleets = 0;
        double fleetTime = 0;

        for (const auto& [pos, spd] : cars) {
            double time = static_cast<double>(target - pos) / spd;

            if (time > fleetTime) {
                ++fleets;
                fleetTime = time;
            }
        }
        return fleets;
    }
};
