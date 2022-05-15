#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::cerr;
using std::stringstream ;
using std::string;
using std::ostream;

unsigned long long int Fibonacci(unsigned int n);
void PrintReverseString(const string& str, ostream& output = cout);
// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size, size_t min);
void SelectionSort(int array[], size_t size, size_t currentIndex);


int main() {
	const size_t ELEMENTS = 7;
	const size_t TESTS = 3;
	int data[][ELEMENTS] = {
			{7, 5, 4, 1, 3, 0, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{8, 5, 4, 1, 3, 4, 0}};

	int minimumSolutions[] = {5, 0, 6};
	int sortedArrays[][7] = {
			{0, 1, 3, 4, 5, 7, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{0, 1, 3, 4, 4, 5, 8}};

	unsigned long long int fibonacciSequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	string strings[] = {"hello", "aardvark", "reviver"};
	string reverses[] = {"olleh", "kravdraa", "reviver"};
	size_t passed = 0;
	int minimumResponses[TESTS];
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = -1;
	}

	cout << "Testing Fibonacci" << endl;
	for (int i = 0; i < 10; ++i) {
		unsigned long long int fibonacci = Fibonacci(i);
		if (fibonacci == fibonacciSequence[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}

	cout << "Testing Minimum Position Finding" << endl;
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = MinimumPosition(data[i], ELEMENTS, 0);
		if (minimumResponses[i] == minimumSolutions[i]){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Sorting" << endl;
	bool equal;
	for (int i = 0; i < TESTS; ++i) {
		SelectionSort(data[i], ELEMENTS, 0);
		equal = true;
		for (int j = 0; j < ELEMENTS; ++j) {
			if (data[i][j] != sortedArrays[i][j]){
				equal = false;
				cerr << "Test " << i << " position " << j << " values: ";
				cerr << data[i][j] << " " << sortedArrays[i][j] << endl;
				break;
			}
		}
		if (equal){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Reverse Strings" << endl;
	stringstream out;
	for (int i = 0; i < TESTS; ++i) {
		out.clear();
		out.str("") ;
		PrintReverseString(strings[i], out);
		if (out.str() == reverses[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}

	return 0;
}

unsigned long long int Fibonacci(unsigned int n){
    if (n == 0 || n==1) {
        return n;
    } else {
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
	return 0;
}
void PrintReverseString(const string& str, ostream& output){
    // call PrintReverseString
    // Then output the
    output << str[str.size()-1];
    string  rev = str.substr(0, str.size()-1);
    if (rev.size() > 0) {
        PrintReverseString(rev,output);
    }
}
// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size, size_t minIndex){
    if (size == minIndex) {
        return minIndex;
    } else {
        if (array[size-1] < array[minIndex]) {
            return MinimumPosition(array, size, minIndex+1);
        } else {
            return MinimumPosition(array, size-1, minIndex);
        }
    }
}

// Selects the first element of the array and swaps it with the smallest
//element of the array.
//Then it does selection sort on the array starting at the next position.
//It will stop when there is only one element.
void SelectionSort(int array[], size_t size, size_t currentIndex){
    int minimum;
    int tmp;
    if (currentIndex == size) {
        // base case
        return;
    } else {
        minimum = MinimumPosition(array, size, currentIndex);
        // Swap the first array element with the minimum element
        // use size as the index

        if (currentIndex == minimum) {
            // go to the next call
            return SelectionSort(array, size, currentIndex + 1);
        } else {

            tmp = array[minimum];
            array[minimum] = array[currentIndex];
            array[currentIndex] = tmp;

            return SelectionSort(array, size, currentIndex + 1);
        }
    }
}
