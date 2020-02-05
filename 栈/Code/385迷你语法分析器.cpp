/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger result;
        if(s[0] == '-' || s[0] >= '0' && s[0] <= '9'){
            int number = 0;
            string::iterator iter = s.begin();
            if(s[0] == '-') iter++;
            while(iter != s.end()){
                number = number * 10 + *iter - 48;
                iter++;
            }
            if(s[0] == '-') number = -number;
            result.setInteger(number);
        } else{
            stack<NestedInteger>NIStack;
            for(string::iterator iter = s.begin(); iter != s.end(); iter++){
                if(*iter == '['){
                    NestedInteger newNI;
                    NIStack.push(newNI);
                } else if(*iter == '-' || *iter >= '0' && *iter <= '9'){
                    int number = 0, flag = 0;
                    if(*iter == '-'){
                        iter++;
                        flag = 1;
                    }
                    while(iter != s.end() && *iter >= '0' && *iter <= '9'){
                        number = number * 10 + *iter - 48;
                        iter++;
                    }
                    iter--;
                    if(flag) number = -number;
                    NestedInteger subNI(number);
                    (NIStack.top()).add(subNI);
                } else if(*iter == ']'){
                    NestedInteger topNI = NIStack.top();
                    NIStack.pop();
                    if(!NIStack.empty()){
                        (NIStack.top()).add(topNI);
                    } else{
                        result = topNI;
                    }
                }
            }
        }
        return result;
    }
};