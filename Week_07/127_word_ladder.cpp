class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = 1;
        if (wordList.empty()) {
            return 0;
        }    
        unordered_set<string> Set(wordList.begin(), wordList.end());
        if (Set.find(endWord) == Set.end()) {
            return 0;
        }
        if (Set.find(beginWord) != Set.end()) {
            Set.erase(beginWord);
        }
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int n = q.size();
            for (int j = 0; j < n; j++) {//one layer
                string temp = q.front();
                q.pop();
                for (int i = 0; i < temp.size(); i++) {//all children
                    char ori = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        auto it = Set.find(temp);
                        if (it != Set.end()) {
                            if (*it == endWord) {
                                return step + 1;
                            }else {                                
                                q.push(*it);
                                Set.erase(*it);
                            }
                        }else {
                            continue;
                        }
                    }
                    temp[i] = ori;
                }
            }
            step++;
        }
        return 0;
    }
};