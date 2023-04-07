/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 14.03.2023
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "student.h"

using namespace std;

// default constructor to initalize with empty values
Student::Student() {
    m_name = "";
    m_gpa = 0;
    m_gre = 0;
    m_toefl = 0;
}

// constructor with args for name, gpa, gre, toefl
Student::Student(string name, float gpa, int gre, int toefl) {
    m_name = name;
    m_gpa = gpa;
    m_gre = gre;
    m_toefl = toefl;
    print_log();
}

// copy constructor
Student::Student(const Student &student) {
    m_name = student.get_name();
    m_gpa = student.get_gpa();
    m_gre = student.get_gre();
    m_toefl = student.get_toefl();
    m_num_of_app = student.get_num_of_app();
    print_log();
}

// destructor to log out students
Student::~Student() {
    cout << get_name() << " logged out of the system with " << get_num_of_app() << " application(s)." << endl;
}

// to be called when a student applicates to a uni in order to increase total num of applications
void Student::apply_to_uni() const {
    this->m_num_of_app++;
}