class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ranSize = ransomNote.size(), magSize = magazine.size();
        unordered_map<char, int>ranMap, magMap;
        for(int i = 0; i < ranSize; i++){
            if(ranMap.count(ransomNote[i]) == 0) ranMap[ransomNote[i]] = 1;
            else ranMap[ransomNote[i]]++;
        }
        for(int i = 0; i < magSize; i++){
            if(magMap.count(magazine[i]) == 0) magMap[magazine[i]] = 1;
            else magMap[magazine[i]]++;
        }
        for(auto iter = ranMap.begin(); iter != ranMap.end(); iter++){
            if(magMap.count(iter->first) && iter->second <= magMap[iter->first]) continue;
            else return false;
        }
        return true;
    }
};