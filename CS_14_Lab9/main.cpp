//Created by Jayden Lui,  Viktoriia Liu and Kevin Brewer

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
const int NUMBERS_SIZE = 50000;
int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[], int arr3[]) {
    int i;
    for(i = 0; i < NUMBERS_SIZE; ++i) {
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr2[i];
    }
}
//partition for Quicksort_midpoint
int partition1(int numbers[], int i, int k) {
    int midpoint = i + (k - i)/2;
    int pivot = numbers[midpoint];
    bool done = false;
    while(!done) {
        while(numbers[i] < pivot) {
            i += 1;
        }
        while(pivot < numbers[k]) {
            k -= 1;
        }
        if(i >= k) {
            done = true;
        }
        else {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            i += 1;
            k -= 1;
        }
    }
    return k;
}
void Quicksort_midpoint(int numbers[], int i, int k) {
    if (i >= k) {
        return;
    }
    int lowIndex = partition1(numbers, i, k);
    Quicksort_midpoint(numbers, i, lowIndex);
    Quicksort_midpoint(numbers,lowIndex + 1,k);
}
//partition for Quicksort_medianOfThree
int partition2(int numbers[], int i, int k) {
    int midpoint = i + (k - i) / 2;
    int pivot = 0;
    bool done = false;
    if (numbers[midpoint] > numbers[i]) {
        if (numbers[midpoint] > numbers[k]) { // right most is median
            pivot = numbers[k];
        }
        else { // midpoint is median 
            pivot = numbers[midpoint];
        }
    }
    else {
        if (numbers[i] > numbers[k]) { // right most is median
            pivot = numbers[k];
        }
        else { // left most is median
            pivot = numbers[i];
        }
    }
    while (!done) {
        while (numbers[i] < pivot) {
            ++i;
        }
        while (pivot < numbers[k]) { 
            --k;
        }
        if (i >= k) { // If there are 0 or 1 elements remaining, return k
            done = true;
        }
        else {
            // Swap numbers[i] and numbers[k]
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            ++i;
            --k;
        }
    }
    return k;
}
void Quicksort_medianOfThree(int numbers[],int i , int k) {
    if (i >= k) {
        return;
    }
    int lowIndex = partition2(numbers, i, k);
    Quicksort_medianOfThree(numbers, i, lowIndex);
    Quicksort_medianOfThree(numbers,lowIndex + 1,k);
}
void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 1; i < numbersSize; ++i) {
        j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}
int main() {
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1,arr2,arr3);
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;
    clock_t Start1 = clock();
    Quicksort_midpoint(arr1,0,NUMBERS_SIZE-1);
    clock_t End1 = clock();
    int elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS;
    cout << "QuickSort_midpoint Time: " << elapsedTime1 << endl;
    clock_t Start2 = clock();
    Quicksort_medianOfThree(arr2,0,NUMBERS_SIZE-1);
    clock_t End2 = clock();
    int elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS;
    cout << "QuickSort_medianOfThree Time: " << elapsedTime2 << endl;
    clock_t Start3 = clock();
    InsertionSort(arr3,NUMBERS_SIZE);
    clock_t End3 = clock();
    int elapsedTime3 = (End3 - Start3)/CLOCKS_PER_MS;
    cout << "InsertionSort Time:" << elapsedTime3 << endl;
    return 0;
}