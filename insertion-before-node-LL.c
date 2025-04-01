#include <stdio.h>
#include <stdlib.h>

struct slist {
    int value;
    struct slist *next;
} *start = NULL;
typedef struct slist node;

void create() 
{
    node *tmp, *tmp1;
    tmp = (node*)malloc(sizeof(node));
    
    if (tmp == NULL) 
    {
        printf("Memory allocation failed!\n");
        return;
    }

    tmp->next = NULL;
    printf("Enter value for new node: ");
    scanf("%d", &tmp->value);

    if (start == NULL) 
    {
        start = tmp;
    } else 
    {
        tmp1 = start;
        while (tmp1->next != NULL) 
        {
            tmp1 = tmp1->next;
        }
        tmp1->next = tmp;
    }
}

void display() 
{
    node *tmp;
    tmp = start;

    if (tmp == NULL) 
    {
        printf("List is empty !!\n");
    } else {
        printf("Linked List: ");
        while (tmp != NULL) 
        {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void insert_before() {
    node *tmp, *tmp1, *tmp2;
    int num, val;

    if (start == NULL) {
        printf("List is empty!! Cannot insert.\n");
        return;
    }

    printf("\nEnter the value to insert: ");
    scanf("%d", &num);
    printf("Enter the value before which to insert: ");
    scanf("%d", &val);

    tmp = (node*)malloc(sizeof(node));
    if (tmp == NULL) {
        printf("Memory allocation failed!\n");
    }
    tmp->value = num;

    if (start->value == val) {
        tmp->next = start;
        start = tmp;
        printf("Node inserted before %d successfully!\n", val);
        return;
    }

    tmp1 = start;
    tmp2 = NULL;

    while (tmp1 != NULL && tmp1->value != val) {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }

    if (tmp1 == NULL) {
        printf("Value %d not found in the list!\n", val);
        free(tmp);
        return;
    }

    tmp2->next = tmp;
    tmp->next = tmp1;

    printf("Node inserted before %d successfully!\n", val);
}

int main() 
{
    int choice;
    while (1) {
        printf("\n1->For creating a new node \n2->For displaying list \n3->For inserting before a given value \n4->Exit \nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
            create();
        else if (choice == 2)
            display();
        else if (choice == 3)
            insert_before();
        else if (choice == 4)
            break;
        else
            printf("Wrong choice entered !!\n");
    }
    return 0;
}
