#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double calculateCGPA(double** gradePoints, int** credits, int numSemesters, int* numCourses) {
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numSemesters; ++i) {
        for (int j = 0; j < numCourses[i]; ++j) {
            totalGradePoints += gradePoints[i][j] * credits[i][j];
            totalCredits += credits[i][j];
        }
    }

    if (totalCredits == 0) {
        return 0.0;
    }

    return totalGradePoints / totalCredits;
}

double calculateSGPA(double* gradePoints, int* credits, int numCourses) {
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        totalGradePoints += gradePoints[i] * credits[i];
        totalCredits += credits[i];
    }

    if (totalCredits == 0) {
        return 0.0;
    }

    return totalGradePoints / totalCredits;
}

int main() {
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    int* numCourses = new int[numSemesters];
    string** courseNames = new string*[numSemesters];
    double** gradePoints = new double*[numSemesters];
    int** credits = new int*[numSemesters];
    char** grades = new char*[numSemesters];

    for (int i = 0; i < numSemesters; ++i) {
        cout << "Enter the number of courses for semester " << i + 1 << ": ";
        cin >> numCourses[i];

        courseNames[i] = new string[numCourses[i]];
        gradePoints[i] = new double[numCourses[i]];
        credits[i] = new int[numCourses[i]];
        grades[i] = new char[numCourses[i]];

        cout << "Enter the course details in semester " << i + 1 << ":\n";
        for (int j = 0; j < numCourses[i]; ++j) {
            cout << "Course " << j + 1 << "\nName: ";
            cin.ignore();
            getline(cin, courseNames[i][j]);
            cout << "Grade Points: ";
            cin >> gradePoints[i][j];
            cout << "Credits: ";
            cin >> credits[i][j];
            cout << "Grade: ";
            cin >> grades[i][j];
        }
    }

    //SGPA
    for (int i = 0; i < numSemesters; ++i) {
        double sgpa = calculateSGPA(gradePoints[i], credits[i], numCourses[i]);
        cout << "\nSGPA for Semester " << i + 1 << ": " << sgpa << endl;
    }

    //CGPA
    double cgpa = calculateCGPA(gradePoints, credits, numSemesters, numCourses);
    cout << "\nYour CGPA is: " << cgpa << endl;

    for (int i = 0; i < numSemesters; ++i) {
        cout << "\nSemester " << i + 1;
        cout<< " Course Details:\n";
        cout << left << setw(15) ;
        cout<< "Course Name" << setw(15) << "Grade Points" << setw(10) << "Credits" << setw(10) << "Grade" << endl;
        for (int j = 0; j < numCourses[i]; ++j) {
            cout << left << setw(15) << courseNames[i][j] << setw(15) << gradePoints[i][j] << setw(10) << credits[i][j] << setw(10) << grades[i][j] << endl;
        }
    }

    for (int i = 0; i < numSemesters; ++i) {
        delete[] courseNames[i];
        delete[] gradePoints[i];
        delete[] credits[i];
        delete[] grades[i];
    }
    delete[] courseNames;
    delete[] gradePoints;
    delete[] credits;
    delete[] grades;
    delete[] numCourses;

    return 0;
}
