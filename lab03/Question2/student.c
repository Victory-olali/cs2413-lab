// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      // Hints (optional):    
      // - Use a dummy node to simplify edge cases.
      // - Keep track of previous and current pointers.

      struct ListNode dummy;
      dummy.next = head;
      struct ListNode* prev = &dummy;           
      while (prev->next != NULL && prev->next->next != NULL) {
          struct ListNode* first = prev->next;
          struct ListNode* second = prev->next->next;

          // Swap nodes
          first->next = second->next;
          second->next = first;
          prev->next = second;

          // Move prev pointer two nodes ahead
          prev = first;
      }
      return dummy.next;
}