/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
ListNode* merge(ListNode* left, ListNode* right) {
    if (!left) {
        return right;
    } else if (!right) {
        return left;
    }
    ListNode *head, *node;
    if(left->val < right->val) {
        head = left;
        left = left->next;
        head->next = NULL;
    } else {
        head = right;
        right = right->next;
        head->next = NULL;
    }
    node = head;
    while (left && right) {
        if(left->val < right->val) {
            head = head->next = left;
            left = left->next;
            head->next = NULL;
        } else {
            head = head->next = right;
            right = right->next;
            head->next = NULL;
        }
    }
    while (left) {
        head = head->next = left;
        left = left->next;
        head->next = NULL;
    }
    while (right) {
        head = head->next = right;
        right = right->next;
        head->next = NULL;
    }
    return node;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    } else if (listsSize == 1) {
        return lists[0];
    }
    int lft_sz = listsSize / 2;
    int rht_sz = listsSize - lft_sz;
    ListNode* left = mergeKLists(lists, lft_sz);
    ListNode* right = mergeKLists(lists + lft_sz, rht_sz);
    return merge(left, right);
}