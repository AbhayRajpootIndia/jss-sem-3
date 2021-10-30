#include <stdio.h>

int stack[1000] = {1, 3, 5}, size = 3, choice;
int new_val;

void display_stack() {

  printf("{");

  for(int i = 0; i < size; i++) {
    printf("%d, ", stack[i]);
  }

  printf("}\n");
}


void push(int new_val) {

  stack[size] = new_val;
  size++;

  printf("Value added successfully.\n");

}


void pop() {

  if (size > 0){
      size--;
      printf("1 value deleted.\n");
  }
  else {
      printf("Stack is empty.\n");
  }

}


void clear_stack() {
  if (size > 0) size = 0;
}



int main() {

  while (1) {
    printf("\nWhich function to perform?\n");
    printf("1. Display stack\n");
    printf("2. Add a value\n");
    printf("3. Delete a value\n");
    printf("4. Clear stack\n");
    printf("5. Exit\n");

    printf("\nEnter you choice: ");
    scanf("%d", &choice);

    switch (choice) {

      case 1: display_stack(); break;

      case 2: printf("Enter value to add to stack: ");
              scanf("%d", &new_val);

              push(new_val);
              break;

      case 3: pop(); break;

      case 4: clear_stack(); break;

      case 5: return 0;

      default: printf("Please enter a valid option.\n");

    }


  }

  return 0;
}
