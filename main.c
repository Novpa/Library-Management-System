#include <stdio.h>

int interpolationSearcher(int* arr, int size, int search) {
  int lower = 0;
  int upper = size - 1;

  while (arr[lower] <= arr[upper] && search <= arr[upper] &&
         search >= arr[lower]) {
    if (arr[lower] == arr[upper]) {
      if (search == arr[lower])
        return lower;
      else
        break;
    }

    int result = lower + (search - arr[lower]) * (upper - lower) /
                             (arr[upper] - arr[lower]);

    if (result < lower || result > upper) break;

    if (arr[result] == search) return result;

    if (arr[result] < search) lower = result + 1;

    if (arr[result] > search) upper = result - 1;
  }
  return -1;
}

int main() {
  int search;
  int arr[] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 16, 20};

  int size = sizeof(arr) / sizeof(arr[0]);
  printf("Search number (1 - 11) in the data: ");
  scanf("%d", &search);

  int result = interpolationSearcher(arr, size, search);

  printf("result = %d\n", result);
  return 0;
}
// l = index of lower element
// h = index of higher element
// x = value of element will be searched
// Formula = l + ((x - a[l])/(a[h] - a[l])) * (h - l);