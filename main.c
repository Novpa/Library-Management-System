#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This works for sorted data only
int interpolationSearcher(int* arr, int search){
  int higher = sizeof(arr)/sizeof(arr[0]) - 1;
  int lower = 0;
  int result = lower + (search - arr[lower])  * (higher - lower) / (arr[higher] -  arr[lower]);
 if(arr[result] == search){
  return result;
 } else if(arr[result] < search){
  lower = result + 1;
 } else if(arr[result] > search){
  higher = result - 1;
 }

}

int main(){

int search;
int arr[] = {1,2,3,4,5,6,7,8,9,10,11,16,20};
  printf("Search number (1 - 11) in the data: ");
  scanf("%d", &search);

int result = interpolationSearcher(arr, search);

printf("result = %d\n", result);
  return 0;
}
  // l = index of lower element
  // h = index of higher element
  // x = value of element will be searched
  // Formula = l + ((x - a[l])/(a[h] - a[l])) * (h - l);
  