#include <stdio.h>

int que[1000] = {1, 3, 5}, size = 3, choice;
int new_val;

void display_que() {

  printf("{ ");

  for(int i = 0; i < size; i++) {
    printf("%d, ", que[i]);
  }

  printf(" }\n");
}

void push(int new_val) {

  que[size] = new_val;
  size++;

  printf("Value added successfully.\n");

}

void pop() {

  if (size > 0) {
      for(int i = 0; i < size; i++) {
        que[i] = que[i + 1];
      }

      size--;

      printf("1 value deleted.\n");
  }
  else {
      printf("Que is empty.\n");
  }

}

void clear_que() {
  if (size > 0) size = 0;
}



int main()
{
  while (1) {
    printf("\nWhich function to perform?\n");
    printf("1. Display que\n");
    printf("2. Add a value\n");
    printf("3. Delete a value\n");
    printf("4. Clear que\n");
    printf("5. Exit\n");

    printf("\nEnter you choice: ");
    scanf("%d", &choice);

    switch (choice) {

      case 1: display_que(); break;

      case 2:
              printf("Enter value to add to que: ");
              scanf("%d", &new_val);

              push(new_val);
              break;
      case 3: pop(); break;

      case 4: clear_que(); break;

      case 5: return 0;

      default: printf("Please enter a valid option.\n");

    }

  }

  return 0;
}
