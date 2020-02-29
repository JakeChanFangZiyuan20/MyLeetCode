class Solution {
private:
    unordered_set<char>vowelSet{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    string reverseVowels(string s) {
        int len = s.size();
        if(len == 0 || len == 1) return s;

        int head = 0, tail = len - 1;
        while(head < tail){
            while(head < tail && vowelSet.count(s[head]) == 0){
                head++;
            }
            while(head < tail && vowelSet.count(s[tail]) == 0){
                tail--;
            }
            swap(s[head], s[tail]);

            head++;
            tail--;
        }

        return s;
    }
};