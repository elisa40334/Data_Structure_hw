#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int val;
    struct _Node *nxt;
} Node;

void push_back(Node **head, int n) {
    while(*head)
        head = &(*head)->nxt;

    *head = malloc(sizeof(Node));
    (*head)->val = n;
}

void print(Node *head) {
    while(head) {
        printf("%d ", head->val);
        head = head -> nxt;
    }
}
void reverse(Node** head){
    Node *ans = NULL;
    while(*head) {
        if (ans == NULL)
        {
            Node *temp;
            temp = malloc(sizeof(Node));
            temp->nxt = NULL;
            temp->val = (*head)->val;
            ans = temp;
        }
        else
        {
            Node *temp;
            temp = malloc(sizeof(Node));
            temp->nxt = ans;
            temp->val = (*head)->val;
            ans = temp;
        }
        (*head) = (*head)->nxt;
    }
    *head = ans;
}

int main(void) {
    int buf;
    Node *head = NULL;
    while(~scanf(" %d", &buf))
        push_back(&head, buf);

    reverse(&head);
    print(head);

    return 0;
}
