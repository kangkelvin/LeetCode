// https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/785/

///////////////////// Method 1: BRUTE FORCE //////////////////////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode *nodeA = headA;
        bool solutionFound = false;
        
        while (true) {
            ListNode *nodeB = headB;
            
            while (true) {                
                if (nodeB == nodeA) {
                    solutionFound = true;
                    return nodeB;
                }
                nodeB = nodeB->next;
                if (nodeB == NULL) break;
            }

            nodeA = nodeA->next;
            if (nodeA == NULL) break;
        }
        
        return NULL;
    }
};
