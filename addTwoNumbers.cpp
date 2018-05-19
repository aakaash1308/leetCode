// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* sum = new ListNode(0); // to return
        ListNode* temp = sum;
        int carry = 0; // this will hold if there is a carry to worry about

        // Till we go through both the numbers completely
        while(l1 != NULL || l2 != NULL)
        {
        	int tempSum = 0; // will hold the temp value by adding two digits

        	// l1 is empty
        	if(l1 == NULL) 
        	{
        		tempSum = l2->val + carry;
        		l2 = l2->next;
        	}
        	
        	// l2 is empty
        	else if(l2 == NULL) 
        	{
        		tempSum = l1->val + carry;
        		l1 = l1->next;
        	}

        	// if both have digits
        	else
        	{
        		tempSum = l2->val + l1->val + carry;
        		l2 = l2->next;
        		l1 = l1->next;
        	}

        	// Now we check if number is more than 10 then we change carry
        	if(tempSum > 9)
        	{
        		tempSum = tempSum % 10; 
        		carry = 1;
        	}
        	else
        		carry = 0;

        	// finally we can add the new number to the node
        	temp->val = tempSum;
            
            // if end of list the next time
            if(l1 == NULL && l2 == NULL)
            {
                if(carry) // if there is a need to put a 1
                    temp->next = new ListNode(1);
                else 
                    break;
            }
            else
                temp->next = new ListNode(0);
        	
            
            temp = temp->next;
        }

        return sum;
    }
};