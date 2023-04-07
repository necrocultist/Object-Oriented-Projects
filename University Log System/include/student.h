/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 14.03.2023
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Student {
    public:
        // default constructor to initialize with default values
        Student();

        // constructor with args for name, gpa, gre, toefl and their default values
        Student(string = "", float = 0, int = 0, int = 0); 

        // copy constructor, takes a student as a parameter and copies its contents
        Student(const Student &); 

        // destructor to log out students
        ~Student();

        // to be called when a student applicates to a uni in order to increase total num of applications
        void apply_to_uni() const;
     
        // inline setters
        void set_name(string name) { m_name = name; };
        
        // inline getters
        string get_name() const { return m_name; };
        float get_gpa() const { return m_gpa; };
        int get_gre() const { return m_gre; };
        int get_toefl() const { return m_toefl; };
        float get_num_of_app() const { return m_num_of_app; };

    private:
        // fields of student class
        string m_name = "";
        float m_gpa = 0;
        int m_gre = 0;
        int m_toefl = 0;
        mutable unsigned int m_num_of_app = 0;

        // to log when a student gets constructed
        void print_log() const { cout << get_name() << " logged in to the system." << endl; };
};