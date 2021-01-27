// https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator it1, it2;
        it1 = nums1.begin();
        it2 = nums2.begin();
        vector<int> mergedNums;
        
        while (it1 != nums1.end() || it2 != nums2.end()) {
            if (it1 == nums1.end()) {
                mergedNums.push_back(*it2);
                it2++;
            }
            else if (it2 == nums2.end()) {
                mergedNums.push_back(*it1);
                it1++;                
            }
            else { // when both it are still in the array
                if (*it1 > *it2) {
                    mergedNums.push_back(*it2);
                    it2++;
                } else {
                    mergedNums.push_back(*it1);
                    it1++;  
                }
            }
        }
        
        // for (auto x:mergedNums) {
        //     cout << x << " ";
        // }
        // cout << endl;
        
        int mergedLen = mergedNums.size();
        if (mergedLen % 2 == 1) {
            return mergedNums[mergedLen / 2];
        } else {
            double out = (mergedNums[mergedLen / 2 - 1] + mergedNums[mergedLen / 2]) / 2.0;
            return out;
        }
    }
};
