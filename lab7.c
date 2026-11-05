#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, data;
    struct node *next;
    struct node *prev;
};

typedef struct node *NODE;

NODE insertend(NODE start, int row, int col, int item) {
    NODE temp, curr;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->row = row;
    temp->col = col;
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL)
        return temp;

    curr = start;
    while(curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    temp->prev = curr;
    return start;
}

void display(NODE start) {
    NODE temp;
    if(start == NULL)
        printf("\n list is empty\n");
    else {
        printf("\nRow\tCol\tData\n");
        temp = start;
        while(temp != NULL) {
            printf("%d\t%d\t%d\n", temp->row, temp->col, temp->data); // Fixed: added \n
            temp = temp->next;
        }
    }
}

void displaymatrix(NODE start, int m, int n) {
    NODE curr;
    curr = start;
    int i, j;
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(curr != NULL && curr->row == i && curr->col == j) {
                printf("%d\t", curr->data);
                curr = curr->next;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main() {
    NODE start = NULL;
    int m, n, i, j, item;

    printf("\n Read order of the matrix\n");
    if (scanf("%d%d", &m, &n) != 2) return 1;

    printf("\n read elements\n");
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if (scanf("%d", &item) != 1) return 1;
            if(item != 0)
                start = insertend(start, i, j, item);
        }
    }

    display(start);
    printf("\n the sparse matrix is \n");
    displaymatrix(start, m, n);

    return 0;
}
