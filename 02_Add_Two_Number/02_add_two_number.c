#include <iostream>
#include <vector> 
using namespace std;
/*
struct ListNode{
    int val;
    struct ListNode
};
*/
struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){
    struct ListNode dummy={0,NULL};
    struct ListNode* cur= &dummy;
    int carry =0;

    while( l1!= NULL || l2!= NULL || carry!= 0){
        int sum = carry;
        if(l1!=NULL){
            sum += l1 -> val;
            l1 =l1 -> next; //move to next node
        }
        if(l2!=NULL){
            sum+=l2 -> val;
            l2= l2 -> next;
        }
        carry = sum/10;
        cur -> next=(struct ListNode*)malloc(sizeof(struct ListNode)); //allocate new memory for new node 
        cur = cur ->next;  // move to next node
        cur -> val= sum%10; 
        cur -> next =NULL;
    }
    return dummy.next;
}
