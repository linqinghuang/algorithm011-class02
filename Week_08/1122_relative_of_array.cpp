class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //count sort
        int count[1001] = {0};
        for (int i = 0; i < arr1.size(); i++) {
            count[arr1[i]]++;
        }
        int pos = 0;
        for (int j = 0; j < arr2.size(); j++) {
            if (count[arr2[j]] == 0) {
                continue;
            }else {
                while (count[arr2[j]] > 0) {
                    arr1[pos++] = arr2[j];
                    count[arr2[j]]--;
                }
            }
        }
        for (int i = 0; i < 1001; i++) {
            if (count[i] == 0) {
                continue;
            }else {
                while (count[i] > 0) {
                    arr1[pos++] = i;
                    count[i]--;
                }              
            }
        }
        return arr1;
    }
};