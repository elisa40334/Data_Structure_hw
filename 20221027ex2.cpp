#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
using TestCase = ListNode* (*)();


class Solution {
public:
    struct ListNode *detectCycle(struct ListNode *head) {
        struct ListNode *ptr1, *ptr2, *ptr3;
    
        if (head == NULL) {
            return NULL;
        }
        ptr1 = head;
        ptr2 = head;
        while ((ptr2 != NULL) && (ptr2->next != NULL)) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if (ptr1 == ptr2) {
                ptr3 = head;
                while (ptr1 != ptr3) {
                    ptr1 = ptr1->next;
                    ptr3 = ptr3->next;
                }
                return ptr1;
            }
        }
        return NULL;
    }
};

auto append(ListNode** head, ListNode* newNode = nullptr) -> ListNode* {
    while (*head) {
        head = &(*head)->next;
    }
    if (newNode) {
        *head = newNode;
    } else {
        *head = new ListNode(rand());
    }
    return *head;
}

auto test1() -> ListNode* {
    ListNode* head = nullptr;
    ListNode *beg, *ed;
    append(&head, new ListNode(3));
    beg = append(&head, new ListNode(2));
    append(&head, new ListNode(0));
    ed = append(&head, new ListNode(-4));
    ed->next = beg;
    return head;
}

auto test2() -> ListNode* {
    ListNode* head = nullptr;
    ListNode *ed, *beg;
    beg = append(&head, new ListNode(1));
    ed = append(&head, new ListNode(2));
    ed->next = beg;
    return head;
}

auto test3() -> ListNode* {
    ListNode* head = nullptr;
    append(&head, new ListNode(1));
    return head;
}

TestCase testcases[] = {&test1, &test2, &test3};

int main() {
    int n;
    cin >> n;
    ListNode* head = testcases[n - 1]();
    Solution sol;
    ListNode* res = sol.detectCycle(head);
    if (res) {
        cout << res->val << '\n';
    } else {
        cout << "NULL\n";
    }
    return 0;
}
