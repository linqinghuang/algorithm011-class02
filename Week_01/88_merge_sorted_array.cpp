class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.size() == 0){
            return;
        }
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> bufferVector(m + n, 0);//O(n) space complexity
        while(i < m || j < n){
            if(i < m && j < n){
                if (nums1[i] > nums2[j]){
                    bufferVector[k] = nums2[j];
                    j++;
                }else{
                    bufferVector[k] = nums1[i];
                    i++;
                }
                k++;
            }else{
                // i == m && j < n
                if(i == m){
                    bufferVector.insert(bufferVector.begin() + k, nums2.begin() + j, nums2.end());
                    break;
                }
                // j == n && i < m
                else{
                    bufferVector.insert(bufferVector.begin() + k, nums1.begin() + i, nums1.begin() + m);
                    break;
                }
            }
        }
        nums1.erase(nums1.begin(), nums1.begin() + m + n);
        nums1.insert(nums1.begin(), bufferVector.begin(), bufferVector.begin() + m + n);
    }
};