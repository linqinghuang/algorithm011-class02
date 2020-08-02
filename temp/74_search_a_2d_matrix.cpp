class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()){
            return false;
        }
        int columns = matrix[0].size();
        int right = matrix.size() * columns - 1;
        int left = 0;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[mid / columns][mid % columns] == target) {
                return true;
            }
            if (matrix[mid / columns][mid % columns] < target) {
                left = mid + 1;
            }
            if (matrix[mid / columns][mid % columns] > target) {
                right = mid - 1;
            }
        }
        return false;
    }
};