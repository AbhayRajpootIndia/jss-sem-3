#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int cf, px, py, pz;
    int flag;
    struct node* next;
};

typedef struct node NODE;

NODE* createNode() {
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    return newNode;
}

void display(NODE* head)
{
    if (head -> next == head) {
        printf("\n-> Polynomial does not exist.\n");
    }
    else {
        NODE* temp = head -> next;

        printf("\n");

        while (temp != head) {
            printf("%dx^%dy^%dz^%d", temp -> cf, temp -> px, temp -> py, temp -> pz);

            if (temp -> next != head) printf(" + ");

            temp = temp -> next;
        }

        printf("\n");
    }

    return;
}

NODE* insertRear(NODE* head, int cf, int px, int py, int pz)
{
    NODE* newNode = createNode();
    newNode -> cf = cf;
    newNode -> px = px;
    newNode -> py = py;
    newNode -> pz = pz;

    if (head -> next == head) {
        head -> next = newNode;
        newNode -> next = head;
    }
    else {
        NODE* temp = head;

        while (temp -> next != head) {
            temp = temp -> next;
        }

        temp -> next = newNode;
        newNode -> next = head;
    }

    return head;
}

NODE* read() {
    NODE* head = createNode();
    head -> next = head;

    int n = 0;
    printf("\nEnter the number of terms: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("\nEnter a value greater than 1.\n");
        return NULL;
    }

    int cf = 0, px = 0, py = 0, pz = 0;

    for (int i = 1; i <= n; i++) {
        printf("\nTerm %d:", i);

        printf("\nEnter the coefficient: ");
        scanf("%d", &cf);

        printf("Enter the powers of x, y, z: ");
        scanf("%d%d%d", &px, &py, &pz);

        head = insertRear(head, cf, px, py, pz);
    }

    return head;
}

void eval() {
    printf("\nEnter the polynomial:-\n");
    NODE* h = read();

    int x = 0, y = 0, z = 0;
    printf("\nEnter the values of x, y, z to evaluate: ");
    scanf("%d%d%d", &x, &y, &z);

    float result = 0.0;

    NODE* temp = h -> next;

    while(temp != h) {
        result += (temp -> cf) * pow(x, temp -> px) * pow(y, temp -> py) * pow(z, temp -> pz);
        temp = temp -> next;
    }

    printf("\nThe result is = %f", result);

    return;
}

void add()
{
    printf("\nEnter the two polynomials to add: \n");

    NODE* h1 = createNode();
    h1 -> next = h1;

    printf("\nPolynomial 1: ");
    h1 = read(h1);

    NODE* h2 = createNode();
    h2 -> next = h2;

    printf("\nPolynomial 2: ");
    h2 = read(h2);

    NODE* h3 = createNode();
    h3 -> next = h3;

    int cf = 0;

    int cf1 = 0, cf2 = 0;
    int x1 = 0, x2 = 0;
    int y1 = 0, y2 = 0;
    int z1 = 0, z2 = 0;

    NODE* p1 = h1 -> next;
    NODE* p2 = h2 -> next;

    while (p1 != h1) {
        cf1 = p1 -> cf;
        x1 = p1 -> px;
        y1 = p1 -> py;
        z1 = p1 -> pz;

        while (p2 != h2) {
            cf2 = p2 -> cf;
            x2 = p2 -> px;
            y2 = p2 -> py;
            z2 = p2 -> pz;

            if (x1 == x2 && y1 == y2 && z1 == z2) {
                break;
            }

            p2 = p2 -> next;
        }

        if (p2 != h2) {
            p2 -> flag = 1;
            p1 -> flag = 1;
            cf = cf1 + cf2;

            if (cf != 0) {
                h3 = insertRear(h3, cf, x1, y1, z1);
            }
        }
        else {
            h3 = insertRear(h3, cf1, x1, y1 ,z1);
        }

        p1 = p1 -> next;
    }

    p2 = h2;

    while (p2 != h2) {
        if (p2 -> flag == 0) {
            h3 = insertRear(h3, p2 -> cf, p2 -> px, p2 -> py, p2 -> pz);
        }

        p2 = p2 -> next;
    }

    p1 = h1;

    while (p1 != h1) {
        if (p1 -> flag == 0) {
            h3 = insertRear(h3, p1 -> cf, p1 -> px, p1 -> py, p1 -> pz);
        }

        p1 = p1 -> next;
    }

    printf("\nThe resultant polynomial is: ");

    h3 = insertRear(h3, 1,2,3,4);
    display(h3);

    return;
}


void menu()
{
    int choice = 0;

    while (1) {
        printf("\n-- MENU --\n");
        printf("1. Evaluate\n");
        printf("2. Add polynomial\n");
        printf("3. Exit\n");

        printf("\n-> Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: eval(); break:

            case 2: add(); break;

            case 3: return;

            default: printf("\nEnter a valid choice\n");
        }
    }

    return;
}


void main() {
    menu();
}

