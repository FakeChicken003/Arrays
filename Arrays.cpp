/// @file Arrays.cpp
/// @author Jordan Scherf <5005736913@student.csn.edu>
/// @date 004/18/2021
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This lab demonstates [The use of Arrays] to sort an array, find it's
/// max, min, sum, mean, median, and standared deviation.
/// @note Time Taken to Develop Program is about 8 hours
/// between days 04/14 and 04/18  with Assitance of
/// []

#include <iostream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int minimum(const int numberArray[], int count);
int maximum(const int numberArray[], int count);
int sum(const int numberArray[], int count);
double mean(const int numberArray[], int count);
void sorting(int numberArray[], int count);
int median(const int numberArray[], int count);
double StandardDeviation(const int numberArray[], int count);

int main() {
    int number = 0; // the is gonna  input the numbers
    int count = 0;  // this is make he sive for the array
    const int cap = 100;  // total amount of elements that can be put into array

    int numberArray [cap];  // this the the array

    while (count < cap
           && cin >> number) { // while the size is less than 100 and is taking in numbers

        cin >> number;  // take in a number

        numberArray [count] = number;  // place into the array

        count++;
    }

    cout << "Input numberArray (unsorted):" << '\n';

    for (int i = 0; i < count;
         i++) { // this allows me to print out the array unsorted
        cout << setw(7) << numberArray[i];

        if (i % 10 == 0) {
            cout << '\n';
        }
    }

    sorting(numberArray, count);

    cout << "Input numberArray (sorted)::" <<
         '\n'; // this prints out the array when its sorted

    for (int i = 0; i < count; i++) {
        cout << setw(7) << numberArray[i];

        if (i % 10 == 0) {
            cout << '\n';
        }
    }


    cout << "Count: " << count << '\n';
    cout << "Minimum: " << minimum(numberArray, count) << '\n';
    cout << "Maximum: " << maximum(numberArray, count) << '\n';
    cout << "Sum: " << sum(numberArray, count) << '\n';
    cout << "Mean: " << mean(numberArray, count) << '\n';
    cout << "Median: " << median(numberArray, count) << '\n';
    cout << "Std Dev: " << StandardDeviation(numberArray, count) << '\n';

    return 0;
}
// below is the function to give me the smallest number
int minimum(const int numberArray[], int count) {
    int min;

    for (int i = 0; i < count; i++) {
        if (numberArray[i] < numberArray[i + 1]) {
            min = numberArray[i];
        } else {
            min = numberArray[i + 1];
        }
    }

    return min;
}
// below is the function to give me the highest number
int maximum(const int numberArray[], int count) {
    int max;

    for (int i = 0; i < count; i++) {
        if (numberArray[i] > numberArray[i + 1]) {
            max = numberArray[i];
        } else {
            max = numberArray[i + 1];
        }
    }

    return max;
}
// below is the function to give me the sum of the numbers
int sum(const int numberArray[], int count) {
    int sum = 0;

    for (int i = 0; i < count; i++) {
        sum = sum + numberArray[i];
    }

    return sum;
}
// below is the function to give me the mean of the numbers
double mean(const int numberArray[], int count) {
    int Mean;
    int x;

    for (int i = 0; i < count; i++) {
        x = x + numberArray[i];
    }

    Mean = x / count;
    return Mean;
    // below is the function that will sort the function
}

void sorting(int numberArray[], int count) {
    int temp = 0;

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numberArray[i] > numberArray[j]) {
                temp  = numberArray[i];
                numberArray[i] = numberArray[j];
                numberArray[j] = temp;
            }
        }
    }
}

// below is the function that will find the median
int median(const int numberArray[], int count) {
    int TheMedian = 0;

    if (count % 2 != 0) {
        TheMedian = numberArray[count / 2];
    } else {
        TheMedian = (numberArray[count / 2] + numberArray[(count / 2) - 1]) / 2;
    }

    return TheMedian;
}

// below is the function that will find the stddev
double StandardDeviation(const int numberArray[], int count) {

    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for (i = 0; i < 10; ++i) {
        sum += numberArray[i];
    }

    mean = sum / 10;

    for (i = 0; i < 10; ++i) {
        standardDeviation += pow(numberArray[i] - mean, 2);
    }

    return sqrt(standardDeviation / 10);
}
