/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*>result;
        if(k == 1){
            result.push_back(root);
            return result;
        }

        ListNode *p1 = root;
        int NodeNum = 0;
        //vector<int>count;

        // 计算总结点数
        while(p1 != NULL){
            NodeNum += 1;
            p1 = p1->next;
        }
        
        if(NodeNum < k){ // 总结点数少于k
            for(int i = 1; i <= k; i++){
                if(root != NULL){
                    result.push_back(root);
                    root = root->next;
                    (*(result.end() - 1))->next = NULL;
                } else{
                    result.push_back(NULL);
                }
            }
            return result;
        } else{
            // 计算每部分存储节点数
            int partNum = NodeNum / k, extra = NodeNum % k;
            /*
            for(int i = 1; i <= k; i++){
                if(extra != 0){
                    count.push_back(partNum + 1);
                    extra--;
                } else{
                    count.push_back(partNum);
                }
                //cout << *(count.end() - 1) << ' ';
            }*/

            // 逐个部分数节点并压入结果vector中
            for(int i = 1; i <= k; i++){
                ListNode *newList = NULL, *p2 = NULL;
                int count;
                if(extra){
                    count = partNum + 1;
                    extra--;
                } else{
                    count = partNum;
                }
                for(int j = count; j > 0; j--){
                    //cout << root->val << ',';
                    if(newList == NULL){
                        newList = p2 = root;
                    } else{
                        p2->next = root;
                        p2 = p2->next;
                    }
                    root = root->next;
                    p2->next = NULL;
                }
                cout << endl;
                result.push_back(newList);
            }
        }
            
        return result;
    }
};