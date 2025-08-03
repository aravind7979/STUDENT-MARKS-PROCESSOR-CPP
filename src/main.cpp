#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits> // for input validation

using namespace std;

// Function to safely read n student marks
vector<int> readStudentMarks(int count) {
    vector<int> marks;
    cout << "Enter marks for " << count << " students: ";

    int entered = 0;
    while (entered < count) {
        int val;
        cin >> val;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid integer mark: ";
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            continue;
        }

        marks.push_back(val);
        entered++;
    }

    return marks;
}

// Function to display the marks using const_iterator (read-only)
void displayOriginalMarks(const vector<int>& marks) {
    cout << "Original student marks: ";
    for (vector<int>::const_iterator it = marks.begin(); it != marks.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

// Function to process the marks: sort, insert bonus, reverse
void processMarks(vector<int>& marks) {
    // Sort the marks in ascending order
    sort(marks.begin(), marks.end());

    // Bonus marks to be inserted
    vector<int> bonusMarks = {99, 100};

    // Insert bonus marks after the 2nd mark (i.e., index 2)
    auto insertPosition = marks.begin() + 2;
    copy(bonusMarks.begin(), bonusMarks.end(), inserter(marks, insertPosition));

    // Reverse the entire list so highest marks come first
    reverse(marks.begin(), marks.end());
}

// Function to display final marks using ostream_iterator
void displayFinalMarks(const vector<int>& marks) {
    cout << "✅ Final marks after sorting, bonus insertion, and reversing: ";
    ostream_iterator<int> output(cout, " ");
    copy(marks.begin(), marks.end(), output);
    cout << endl;
}

// Main function  
int main() {
    const int numberOfStudents = 5;

    // Step 1: Read
    vector<int> studentMarks = readStudentMarks(numberOfStudents);

    // Step 2: Display before processing
    displayOriginalMarks(studentMarks);

    // Step 3: Sort, insert bonus, and reverse
    processMarks(studentMarks);

    // Step 4: Final output
    displayFinalMarks(studentMarks);

    return 0;
}