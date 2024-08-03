class Solution {
public:
    int largestAltitude(const std::vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for (const auto& g : gain) {
            currentAltitude += g;
            maxAltitude = std::max(maxAltitude, currentAltitude);
        }
        
        return maxAltitude;
    }
};