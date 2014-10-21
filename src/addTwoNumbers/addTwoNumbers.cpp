// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*               
**********************************************************************************/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, z=0;
        ListNode *h=NULL, *t=NULL;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(&l1);
            y = getValueAndMoveNext(&l2);
            
            z = z + x + y;
            
            ListNode *node = new ListNode(z%10);
            if (h == NULL){
                h = t = node;
            }else{
                t->next = node;
                t = node;
            }
            
            z = z/10;
        }
        
        while (z > 0) {
            ListNode *node = new ListNode(z%10);
            t->next = node;
            z = z/10;
        }
        
        return h;
    }
private:
    int getValueAndMoveNext(ListNode** l){
        int x = 0;
        if ( (*l) != NULL){
            x = (*l)->val;
            (*l) = (*l)->next;
        }
        return x;
    }
};
