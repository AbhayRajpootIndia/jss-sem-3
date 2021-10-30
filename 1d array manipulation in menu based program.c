#include <stdio.h>

int array[1000], size, choice, check, i, pos;

void create_array (int n) {

    printf("Enter the elements of the array:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    check = 1;

}


void print_array() {

    printf("\nThe array is:\n { ");

    for(i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    printf(" }\n");

}

void insert_element(int pos) {

    int new_element = 0;

    printf("Enter the element to insert: ");
    scanf("%d", &new_element);

    for(i = size; i > pos - 2; i--) {
        array[i + 1] = array[i];
    }

    array[pos - 1] = new_element;

    size++;

    printf("\nAdded 1 new value.\n");
}

void delete_element(pos) {

    int deleted_element = array[pos - 1];

    for(i = pos - 1; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    size--;

    printf("\n%d deleted.\n", deleted_element);






}





int main() {

    while(1) {

        printf("\n------------------------------\n");
        printf("Which function to perform?\n");
        printf("1. Create arrray\n");
        printf("2. Display array\n");
        printf("3. Insert an element\n");
        printf("4. Delete an element\n");
        printf("5. Exit\n\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (check == 0) {
                    printf("\nEnter the number of elements in the array: ");
                    scanf("%d", &size);

                    if (size > 0) {
                        create_array(size);
                    }
                    else {
                        printf("Please enter value greater than 0.\n");
                    }

                }
                else {
                    printf("Array created already...\n");
                }

                break;

            case 2:
                if (size > 0) {
                    print_array();
                }
                else if (check == 0) {
                    printf("Array not created...\n");
                }
                else {
                    printf("Array is empty...\n");
                }

                break;

            case 3:
                if (check == 1 ) {
                    printf("Enter position to insert the element into: ");
                    scanf("%d", &pos);

                    if (pos > 0 && pos < size + 2) {
                        insert_element(pos);
                    }
                    else {
                        printf("Please enter position between 1 and %d\n", size + 1);
                    }
                }
                else if (check == 0) {
                    printf("Array not created...\n");
                }
                else {
                    printf("Array is empty...\n");
                }

                break;

            case 4:
                if (check == 1 ) {
                    printf("Enter position of the element delete: ");
                    scanf("%d", &pos);

                    if (pos > 0 && pos <= size) {
                        delete_element(pos);
                    }
                    else {
                        printf("Please enter position between 1 and %d\n", size);
                    }
                }
                else if (check == 0) {
                    printf("Array not created...\n");
                }
                else {
                    printf("Array is empty...\n");
                }

                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Enter a valid choice.\n");




        }


    }


    return 0;
}


