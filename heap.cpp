#include<iostream>
using namespace std;

#define MAX_SIZE 20

class StudentMarksHeap {
private:
    int studentCount;
    int marks[MAX_SIZE];

    void heapify(int marksArray[], int currentIndex, int heapSize) {
        int leftChild, rightChild, largestIndex, temp;
        leftChild = 2 * currentIndex;
        rightChild = 2 * currentIndex + 1;

        if ((leftChild <= heapSize) && marksArray[leftChild] > marksArray[currentIndex])
            largestIndex = leftChild;
        else
            largestIndex = currentIndex;

        if (rightChild <= heapSize && marksArray[rightChild] > marksArray[largestIndex])
            largestIndex = rightChild;

        if (largestIndex != currentIndex) {
            temp = marksArray[currentIndex];
            marksArray[currentIndex] = marksArray[largestIndex];
            marksArray[largestIndex] = temp;
            heapify(marksArray, largestIndex, heapSize);
        }
    }

    void buildMaxHeap(int marksArray[], int size) {
        for (int i = size / 2; i >= 1; i--) {
            heapify(marksArray, i, size);
        }
    }

    void heapSort(int marksArray[], int size) {
        buildMaxHeap(marksArray, size);
        int temp;
        for (int i = size; i >= 2; i--) {
            temp = marksArray[i];
            marksArray[i] = marksArray[1];
            marksArray[1] = temp;
            heapify(marksArray, 1, i - 1);
        }
    }

public:
    void inputMarks() {
        cout << "\nEnter the number of students: ";
        cin >> studentCount;
        cout << "\nEnter the marks of students: ";
        for (int i = 1; i <= studentCount; i++) {
            cin >> marks[i];
        }
        heapSort(marks, studentCount);
    }

    void displaySortedMarks() {
        cout << "\n***SORTED MARKS***" << endl;
        for (int i = 1; i <= studentCount; i++) {
            cout << marks[i] << endl;
        }
    }

    void displayMaximumMarks() {
        cout << "\nMaximum marks obtained are: " << marks[studentCount];
    }

    void displayMinimumMarks() {
        cout << "Minimum marks obtained are: " << marks[1];
    }
};

int main() {
    StudentMarksHeap marksSystem;
    int choice;
    
    while (true) {
        cout << endl << "========MENU=======";
        cout << endl << "1. Input student marks";
        cout << endl << "2. Display sorted marks";
        cout << endl << "3. Find maximum marks";
        cout << endl << "4. Find minimum marks";
        cout << endl << "5. Exit";
        cout << endl << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                marksSystem.inputMarks();
                break;
            case 2:
                marksSystem.displaySortedMarks();
                break;
            case 3:
                marksSystem.displayMaximumMarks();
                break;
            case 4:
                marksSystem.displayMinimumMarks();
                break;
            case 5:
                cout << "\nThank you for using the student marks system!\n";
                exit(0);
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
    return 0;
}