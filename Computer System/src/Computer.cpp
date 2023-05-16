/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 15.04.2023
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Computer.h"

// + operator overload for Computer class to add CPU
void Computer::operator+(const CPU &cpu)
{
    if (mp_attachedCPU != nullptr)  // if cpu is not empty, return (Singleton)
    {
        std::cout << "There is already a CPU" << std::endl;
        return;
    }

    setCPU(cpu);    // set attached cpu
    std::cout << "CPU is attached" << std::endl;
}

// + operator overload for Computer class to add GPU
void Computer::operator+(const GPU &gpu)
{
    if (mp_attachedGPU != nullptr)  // if gpu is not empty, return (Singleton)
    {
        std::cout << "There is already a GPU" << std::endl;
        return;
    }

    setGPU(gpu);    // set attached gpu
    std::cout << "GPU is attached" << std::endl;
}

// Main operation of the Computer System. Regarding the operation input, decides a proper result according to CPU/GPU and prints it.
void Computer::execute(std::string operation) const
{
    std::string result;
    if (operation == "add" || operation == "subtract" || operation == "multiply")   // if the operation is arithmetic, call attached CPU's execute method and set the result
        result = getCPU()->execute(operation);

    else if (operation == "render" || operation == "trainModel")    // if the operation is related to GPU, call attached GPU's execute method and set the result
        result = getGPU()->execute(operation);

    else
    {
        std::cout << "Invalid operation" << std::endl;  // the case where the operation is invalid. Not mandatory in the test case.
        return;
    }

    std::cout << result << std::endl;   // prints the result
}

// execute method of CPU, called when CPU is used in the computer. Returns a string using the ALU object that CPU holds and its operation methods
std::string CPU::execute(const std::string operation) const
{
    int num1, num2;
    getInput(num1, num2);   // calling get input function to supply above declared integers user input

    if (operation == "add")
        return std::to_string(getALU().add(num1, num2));    // if operation is add, call ALU's add method

    else if (operation == "subtract")   // if operation is subtract, call ALU's subtract method
        return std::to_string(getALU().subtract(num1, num2));

    else if (operation == "multiply")   // if operation is multiply, call ALU's multiply method
        return std::to_string(getALU().multiply(num1, num2));

    else    // else return null
        return nullptr;
}

// Method is not mandatory, only to make execute method of CPU cleaner. Gets two integers as reference and supplies them user input
void CPU::getInput(int &num1, int &num2) const
{
    std::cout << "Enter two integers" << std::endl;
    std::cin >> num1 >> num2;
}

// execute method of GPU, called when GPU is used in the computer. Operates using the CUDA object that GPU holds.
std::string GPU::execute(const std::string &operation) const
{
    if (operation == "render") // if operation is render, call CUDA's render method
        return getCUDA().render();

    else if (operation == "trainModel") // if operation is trainModel, call CUDA's train model method
        return getCUDA().trainModel();

    else
        return nullptr; // else, return null
};