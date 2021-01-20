# https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/

# O(n^2*log(n)) solution
class Solution {
public:
    typedef std::tuple<int, int, int> triplet;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if (nums.size() < 3) return output;
        
        std::sort(nums.begin(), nums.end());
        
        std::set<vector<int>> set;
        for (auto it1 = nums.begin(); it1 != nums.end() - 2; ++it1) {
            for (auto it2 = it1 + 1; it2 != nums.end() - 1; ++it2) {
                int sum = *it1 + *it2;
                if (sum > 0) {
                    continue;
                }
                else {
                    auto lowerIt = std::lower_bound(it2+1, nums.end(), -sum);
                    if (lowerIt == nums.end() || *lowerIt != -sum) {
                        continue;
                    }
                    else {
                        vector<int> vec = {*it1, *it2, *lowerIt};
                        std::sort(vec.begin(), vec.end());
                        if (set.find(vec) == set.end()) {
                            set.insert(vec);
                    }
                    }
                }
            }
        }
        
        for (auto vec:set) {
            output.push_back(vec);
        }
        return output;
    }
};

// O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> output;
        std::set<vector<int>> set;
        
        std::unordered_map<int, int> hash;
        for (auto num:nums) {
            if (hash.find(num) == hash.end()) {
                hash[num] = 1;
            } else {
                hash[num]++;
            }
        }
        
        // for (auto pair:hash) {
        //     std::cout << pair.first << " " << pair.second << "\n";
        // }
        
        for (auto &num1:hash) {
            if (num1.second < 1) continue;
            num1.second--;
            for (auto &num2:hash) {
                if (num2.second < 1) continue;
                num2.second--;
                int keyToFind = -(num1.first + num2.first);
                auto it = hash.find(keyToFind);
                if (it != hash.end() && it->second > 0) {
                    vector<int> vec = {num1.first, num2.first, it->first};
                    std::sort(vec.begin(), vec.end());
                    if (set.find(vec) == set.end()) {
                        set.insert(vec);
                    }
                }
                num2.second++;
            }
            num1.second++;
        }
        
        for (auto vec:set) {
            output.push_back(vec);
        }
        return output;
    }
};
