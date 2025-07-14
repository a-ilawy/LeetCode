/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        vector<int> arr;
       while (head != nullptr) {
        arr.push_back(head->val);
        head = head->next;
    }
    int n = arr.size();
    for(int i=0; i<n;i++){
        num += arr[i] * pow(2,n-i-1);
       
    }
        return num;
    }
};