class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> c;
        for(char s : sentence){
            c.insert(s);
        }
        return c.size() == 26;
    }
};