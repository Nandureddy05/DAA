#include <stdio.h>
#include <stdlib.h>

struct Item {
  int value;
  int weight;
};

int maxValue(int capacity, struct Item* items, int n) {
 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (items[j].value / items[j].weight < items[j + 1].value / items[j + 1].weight) {
        struct Item temp = items[j];
        items[j] = items[j + 1];
        items[j + 1] = temp;
      }
    }
  }

  int knapsack[capacity + 1];
  for (int i = 0; i <= capacity; i++) {
    knapsack[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = capacity; j >= items[i].weight; j--) {
      knapsack[j] = max(knapsack[j], knapsack[j - items[i].weight] + items[i].value);
    }
  }

  return knapsack[capacity];
}

int main() {
  int capacity;
  printf("Enter the knapsack capacity: ");
  scanf("%d", &capacity);

  int n;
  printf("Enter the number of items: ");
  scanf("%d", &n);

  struct Item* items = malloc(sizeof(struct Item) * n);

  for (int i = 0; i < n; i++) {
    printf("Enter the value and weight of item %d: ", i + 1);
    scanf("%d %d", &items[i].value, &items[i].weight);
  }

  int maxValue = maxValue(capacity, items, n);

  printf("The maximum value that can be stored in the knapsack is: %d\n", maxValue);

  return 0;
}
