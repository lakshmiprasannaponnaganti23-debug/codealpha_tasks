#include <iostream>
using namespace std;

int main() {
    int n;
    float grade,credits;
    float totalCredits = 0;
    float totalGradePoints = 0;
    cout<<"-------CGPA CALCULATOR-------"<<endl;
    cout<<"Enter number of courses: ";
    cin>>n;
    for(int i=1;i<=n;i++) {
        cout << "\nCourse " << i << endl;
        cout << "Enter grade points : ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> credits;
        totalCredits += credits;
        totalGradePoints += grade * credits;
    }
    float cgpa = totalGradePoints / totalCredits;
    cout << "\n---------------------------" << endl;
    cout << "Total Credits       : " << totalCredits << endl;
    cout << "Total Grade Points  : " << totalGradePoints << endl;
    cout << "Final CGPA          : " << cgpa << endl;
    cout << "---------------------------" << endl;
    return 0;
}