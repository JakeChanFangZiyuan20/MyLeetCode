class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0) return "";
        if(path.size() == 1) return "/";
        
        string element;
        vector<string>stdpath;
        int num = path.size();
        for(int i = 0; i < num; ){
            if(path[i] == '/') {
                i += 1;
            } else{
                element = "";
                for(int j = i; j < num ; j++){
                    if(path[j] == '/') break;
                    element.push_back(path[j]);
                }
                // element == "."，无任何变化，直接i += 1
                if(element == "."){}
                else if(element == ".."){
                    if(stdpath.size() != 0) stdpath.pop_back();
                } else{
                    stdpath.push_back(element);
                }
                i += element.size();
            }
        }

        string resultpath("");
        num = stdpath.size();
        for(int i = 0; i< num; i++){
            resultpath += "/";
            resultpath += stdpath[i];
        }

        if(resultpath.size() == 0) resultpath = "/";
        return resultpath;
    }
};