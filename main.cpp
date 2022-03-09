#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "roster.cpp"

using namespace std;

int main()
{
    const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Spencer,Swift,sswift8@wgu.edu,26,31,31,31,SOFTWARE",
    };

    cout <<"-- TESTING FUNCTIONALITY --" << endl << endl;

    int numStudents = 5;

    Roster* classRoster = new Roster(numStudents); //creates roster
    cout << "-- Adding students:\n";
    for (int i = 0; i < numStudents; i++)
    {
        classRoster->add(studentData[i]); // parse each line turns them into student objects
    }
    cout << "added :" << numStudents << "students. \n\n";
    
    cout << "Displaying all students:\n";
    classRoster->printAll();//displaying all students in the roster
    cout << "\n\n";

    cout << "Displaying all invalid emails:\n";
    classRoster->printInvalidEmails();
    cout << "\n\n";

    cout << "Displaying all security enrolled students:\n";
    classRoster->printByDegreeProgram(SECURITY);
    cout << "\n";

    cout << "Displaying all software enrolled students:\n";
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << "\n";

    cout << "Displaying all network enrolled students:\n";
    classRoster->printByDegreeProgram(NETWORK);
    cout << "\n\n";

    classRoster->printAverageDaysInCourse("A1");//prints average days remaining of specified ID
    cout << "\n";

    cout << "Removing A1:\n"; // Remove the student with the supplied ID
    classRoster->remove("A1");
    cout << "\n";
    classRoster->printAll(); //prints all to show removal
    cout << "\n\n";

    cout << "Removing A1:\n"; //Remove the student again to check error coindition
    classRoster->remove("A1");
    cout << "\n";

    cout << "Success! \n";
    return 0; //exit
}
