/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 14.03.2023
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "university.h"

using namespace std;

// default constructor to initialize with default values
University::University() {
    m_name = "";
    m_gpa_weight = 0;    
    m_gre_weight = 0;
    m_toefl_weight = 0;
    m_bias = 0;
    m_country = "";
}

// constructor with args for uni name, gpa weight, gre weight, toefl weight, bias, uni country and their default values
University::University(string uni_name, float gpa_weight, float gre_weight, float toefl_weight, float bias, string uni_country) {
    m_name = uni_name;
    m_gpa_weight = gpa_weight;    
    m_gre_weight = gre_weight;
    m_toefl_weight = toefl_weight;
    m_bias = bias;
    m_country = uni_country;
}

// copy constructor, takes a university as a parameter and copies its contents
University::University(const University &university) {
    m_name = university.get_uni_name();
    m_gpa_weight = university.get_gpa_weight();    
    m_gre_weight = university.get_gre_weight();
    m_toefl_weight = university.get_toefl_weight();
    m_bias = university.get_bias();
    m_country = university.get_uni_country();
}

// to evaluate overall student score and admit or reject based on the score using perceptron
void University::evaluate_student(const Student &student) {
    student.apply_to_uni();
    
    float score = (student.get_gpa() * get_gpa_weight()) + 
        (student.get_gre() * get_gre_weight()) + (student.get_toefl() * get_toefl_weight()) + get_bias();
    unsigned int final_bin = score < 0 ? 0 : 1;

    if (final_bin == 0) cout << student.get_name() << " is rejected from " << get_uni_name() << "." << endl;
    else cout << student.get_name() << " is admitted to " << get_uni_name() << "." << endl;
}