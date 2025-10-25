#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void inputArray(double arr[], int n, int i = 0) {
    if (i == n) return;
    cout << "arr[" << i << "] = ";
    cin >> arr[i];
    inputArray(arr, n, i + 1);
}

void printArray(double arr[], int n, int i = 0) {
    if (i == n) {
        cout << endl;
        return;
    }
    cout << fixed << setprecision(2) << arr[i] << " ";
    printArray(arr, n, i + 1);
}

int countLess(double arr[], int n, double C, int i = 0) {
    if (i == n) return 0;
    return (arr[i] < C ? 1 : 0) + countLess(arr, n, C, i + 1);
}

int lastNegativeIndex(double arr[], int n, int i = 0) {
    if (i == n) return -1;
    int temp = lastNegativeIndex(arr, n, i + 1);
    if (temp != -1) return temp;
    return (arr[i] < 0 ? i : -1);
}

int sumIntegersAfter(double arr[], int n, int start, int i = 0) {
    if (i == n) return 0;
    if (i <= start) return sumIntegersAfter(arr, n, start, i + 1);
    return int(arr[i]) + sumIntegersAfter(arr, n, start, i + 1);
}

double findMax(double arr[], int n, int i = 0) {
    if (i == n - 1) return arr[i];
    double m = findMax(arr, n, i + 1);
    return (arr[i] > m ? arr[i] : m);
}

void copyCloseToMax(double arr[], double result[], int n, double maxVal, int& j, int i = 0) {
    if (i == n) return;
    if (arr[i] >= maxVal * 0.8) {
        result[j++] = arr[i];
    }
    copyCloseToMax(arr, result, n, maxVal, j, i + 1);
}

void copyOthers(double arr[], double result[], int n, double maxVal, int& j, int i = 0) {
    if (i == n) return;
    if (arr[i] < maxVal * 0.8) {
        result[j++] = arr[i];
    }
    copyOthers(arr, result, n, maxVal, j, i + 1);
}

int main() {
    int n;
    double C;

    cout << "n = ";
    cin >> n;
    cout << "C = ";
    cin >> C;

    double* arr = new double[n];

    cout << "Enter the array elements:" << endl;
    inputArray(arr, n);

    cout << "Initial array: ";
    printArray(arr, n);

    int count = countLess(arr, n, C);
    cout << "Number of elements less than " << C << " = " << count << endl;

    int lastNeg = lastNegativeIndex(arr, n);
    int sumAfter = 0;
    if (lastNeg != -1)
        sumAfter = sumIntegersAfter(arr, n, lastNeg);
    else
        sumAfter = 0;

    cout << "Sum of integer parts after the last negative = " << sumAfter << endl;

    double maxVal = findMax(arr, n);

    double* rearranged = new double[n];
    int j = 0;
    copyCloseToMax(arr, rearranged, n, maxVal, j);
    copyOthers(arr, rearranged, n, maxVal, j);

    cout << "Array after permutation: ";
    printArray(rearranged, n);

    delete[] arr;
    delete[] rearranged;

    return 0;
}
