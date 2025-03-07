#ifndef LL_REMNFOMEND_H
#define LL_REMNFOMEND_H

//define what a linked list node is; 
//  has a value, points to another list node
typedef struct node_t {
  int val;
  struct node_t* next;
} ListNode;

/**
 * Remove the nth node from the end of a linked list.
 *
 * Example, a list is length n, the end of the list index would be n-1..
 * 1 would be the "first node from end", or n-1, 2nd would be n-2, and so on.
 */
ListNode* removeNthFromEndV1(ListNode* head, int n);
ListNode* removeNthFromEndV2(ListNode* head, int n);
ListNode* removeNthFromEnd(ListNode* head, int n);

#endif
