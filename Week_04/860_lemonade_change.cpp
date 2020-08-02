class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.empty()) {
            return true;
        }
        if (bills[0] > 5) {
            return false;
        }
        //0 -- $5, 1 -- $ 10, 2 -- $20, vector use less memory space than hash
        vector<int> count(3, 0);
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                count[0]++;
            }
            else if(bills[i] == 10) {
                if (count[0] > 0) {
                    count[0]--;
                    count[1]++;
                }else {
                    return false;
                }
            }
            //$20
            else {
                //use $10 first, greedy
                if(count[1] > 0 && count[0] > 0) { 
                    count[1]--;
                    count[0]--;
                }else {
                    //use 3 * $5
                    if (count[0] >= 3) {
                        count[0] -= 3;
                    }else{
                        return false;
                    }
                }
            }
        }        
        return true;
    }
};