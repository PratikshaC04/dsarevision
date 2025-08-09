#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Node definition
typedef struct Node {
    char name[50];
    char gender;
    int coupon_number;
    struct Node* next;
} *node;


// Check if stack is empty
int isEmpty(node top) {
    return top == NULL;
}

// Push: returns new top
node push(node top, char name[], char gender, int coupon_number) {
   node newNode = (node)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return top;
    }
    strcpy(newNode->name, name);
    newNode->gender = gender;
    newNode->coupon_number = coupon_number;
    newNode->next = top;
    return newNode;
}

// Pop: returns new top and copies popped data to output variables
node pop(node top, char name[], char* gender, int* coupon_number) {
    if (isEmpty(top)) {
        printf("Stack is empty! Nothing to pop.\n");
        return NULL;
    }

   node temp = top;
    strcpy(name, temp->name);
    *gender = temp->gender;
    *coupon_number = temp->coupon_number;

    top = top->next;
    free(temp);
    return top;
}

// Take customer input and build stack
node inputCustomers(node top, int n) {
    char name[50];
    char gender;
    int coupon_number;

    for (int i = 0; i < n; i++) {
        printf("Enter details for customer %d\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Gender (m/f): ");
        scanf(" %c", &gender);
        printf("Coupon number: ");
        scanf("%d", &coupon_number);

        top = push(top, name, gender, coupon_number);
    }

    return top;
}

// Display winners while popping
void displayPrizeDetails(node top) {
    char name[50];
    char gender;
    int coupon_number;
    int count = 1;

    while (!isEmpty(top)) {
        top = pop(top, name, &gender, &coupon_number);

        printf("\nCustomer %d Details:\n", count++);
        printf("Name: %s\n", name);
        printf("Gender: %c\n", gender);
        printf("Coupon Number: %d\n", coupon_number);

        if (coupon_number % 2 == 0)
            printf("WINS CAR\n");
        else
            printf("WINS BIKE\n");
    }
}

int main() {
    int n;
   node top = NULL;  // Local top pointer

    printf("Enter number of customers: ");
    scanf("%d", &n);

    top = inputCustomers(top, n);
    displayPrizeDetails(top);

    return 0;
}
