/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 14.03.2023
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "student.h"

class University {
    public:
        // default constructor to initialize with default values
        University();

        // constructor with args for uni name, gpa weight, gre weight, toefl weight, bias, uni country and their default values
        University(string = "", float = 0, float = 0, float = 0, float = 0, string = ""); 

        // copy constructor, takes a university as a parameter and copies its contents
        University(const University &);

        // inline getters
        string get_uni_name() const { return m_name; };
        string get_uni_country() const { return m_country; };
        float get_gpa_weight() const { return m_gpa_weight; };
        float get_gre_weight() const { return m_gre_weight; };
        float get_toefl_weight() const { return m_toefl_weight; };
        float get_bias() const { return m_bias;};

        // to evaluate overall student score and admit or reject based on the score using perceptron
        void evaluate_student(const Student &);

    private:
        // fields of student class
        string m_name = "";
        string m_country = "";
        float m_gpa_weight = 0;
        float m_gre_weight = 0;
        float m_toefl_weight = 0;
        float m_bias = 0;
};