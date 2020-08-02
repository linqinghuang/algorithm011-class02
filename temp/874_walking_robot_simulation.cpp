class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for (auto obstacle : obstacles) {
            stopSet.insert(make_pair(obstacle[0], obstacle[1]));
        }
        for(int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2){
                if (dire - 1 < 0) {
                    dire = 3;
                }else {
                    dire = dire - 1;
                }
            }
            else if (commands[i] == -1) {
                if (dire + 1 > 3) {
                    dire = 0;
                }else {
                    dire = dire + 1;
                }
            }
            else {
                movePoint(commands[i]);
            }
        }
        return ans;
    }
private:
    void movePoint(int length) {
        switch(dire) {
            case 0:
                //up add y, consider obstacles
                for (int i = 0; i < length; i++) {
                    auto it = stopSet.find(make_pair(x, y + 1));
                    if (it != stopSet.end()) {
                        ans = max(ans, x*x + y*y);
                        break;
                    }
                    y++;
                }
                ans = max(ans, x*x + y*y);
                break;
            case 1:
                //right add x
                for (int i = 0; i < length; i++) {
                    auto it = stopSet.find(make_pair(x + 1, y));
                    if (it != stopSet.end()) {
                        ans = max(ans, x*x + y*y);
                        break;
                    }
                    x++;
                }
                ans = max(ans, x*x + y*y);
                break;
            case 2:
                //down sub y
                for (int i = 0; i < length; i++) {
                    auto it = stopSet.find(make_pair(x, y - 1));
                    if (it != stopSet.end()) {
                        ans = max(ans, x*x + y*y);
                        break;
                    }
                    y--;
                }
                ans = max(ans, x*x + y*y);
                break;
            case 3:
                //left sub x
                for (int i = 0; i < length; i++) {
                    auto it = stopSet.find(make_pair(x - 1, y));
                    if (it != stopSet.end()) {
                        ans = max(ans, x*x + y*y);
                        break;
                    }
                    x--;
                }
                ans = max(ans, x*x + y*y);
                break;
            default:
                break;
        }

    }    
    //0: up, 1: right, 2: down, 3:left
    int dire = 0;
    int x = 0;
    int y = 0;
    set<pair<int, int>> stopSet;
    int ans = 0;
};