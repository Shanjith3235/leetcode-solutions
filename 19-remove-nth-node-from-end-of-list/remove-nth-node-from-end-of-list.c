/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL) return NULL;
    if(head->next == NULL && n == 1) return NULL;
    struct ListNode* remove = head;
    int size = 0;
    while(remove != NULL) {
        size++;
        remove = remove->next;
    }
    remove = head;
    for(int i = 1; i < size - n; i++) {
        remove = remove->next;
    }
    if(remove->next == NULL) {
        remove->next = NULL;
    }else {
        if(size == n) {
            head = head->next;
        }else {
            remove->next = remove->next->next;
        }
    }
    return head;
}