class Solution {
public:
    string reverseWords(string s) {
        int strSize = s.size();
        if (strSize == 0) return s;

        int count_temp = 2;
        while (count_temp--) {
            for (auto iter = s.begin(); iter != s.end(); ) {
                if (*iter == ' ') s.erase(iter);
                else if (*iter != ' ') break;
            }
            if(count_temp == 1)reverse(s.begin(), s.end());
        }

        for (auto iter = s.begin(); iter != s.end(); ) {
            if (*iter == ' ' && *(iter - 1) == ' ') s.erase(iter);
            else {
                auto iter2 = iter;
                while (iter2 != s.end() && *(iter2) != ' ') {
                    iter2++;
                }

                reverse(iter, iter2);
                if (iter2 == s.end()) break;
                iter = iter2 + 1;
            }
        }

        if (*(s.begin()) == ' ') s.erase(s.end() - 1);

        return s;
    }
};
