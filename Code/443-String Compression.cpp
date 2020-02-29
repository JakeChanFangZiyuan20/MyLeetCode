class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        if(len == 0) return len;

        int i = 0, j = 0, k = 0;
        string curSum;
        for(i; i < len && j < len; ){
            i = j;
            while(j < len && chars[j] == chars[i]){
                j++;
            }
            k++;
            if(j - i >= 2){
                curSum = to_string(j - i);
                for(int pos = 0; pos < curSum.size(); pos++){
                    chars[k++] = curSum[pos];
                }
            }
            if(j < len) chars[k] = chars[j];
        }

        return k;
    }
};