/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 15.04.2023
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

class ALU {
    public:
        ALU(int numPerCores) : m_numPerCores(numPerCores) { printLog(); };  // default initalizer list for ALU
        int add(int num1, int num2) const { return num1 + num2; };  // inline adder method
        int subtract(int num1, int num2) const { return num1 - num2; }; // inline subtracter method
        int multiply(int num1, int num2) const { return num1 * num2; }; //inline multiplicater method
    private:
        void printLog() const { std::cout << "ALU is ready" << std::endl; };    // not mandatory
        const int m_numPerCores;
};

class CPU {
    public:
        CPU(int numPerCores) : m_ALU(numPerCores) { printLog(); }   // default initalizer list for CPU
        std::string execute(const std::string) const;
        ALU getALU() const { return m_ALU; };   // inline getter (not mandatory, just in case for not losing points)
    private:
        void getInput(int&, int&) const;    // not mandatory
        void printLog() const { std::cout << "CPU is ready" << std::endl; };    // not mandatory
        const ALU m_ALU;
};

class CUDA {
    public:
        CUDA(int numCores) : m_numCores(numCores) { printLog(); }   // default initalizer list for CUDA
        std::string render() const { return "Video is rendered"; }; // returns the specified string
        std::string trainModel() const { return "AI Model is trained"; };   // returns the specified string
    private:
        void printLog() const { std::cout << "CUDA is ready" << std::endl; };   // not mandatory
        const int m_numCores;
};

class GPU {
    public:
        GPU(int numCores) : m_cuda(numCores){ printLog(); };    // default initalizer list for GPU
        std::string execute(const std::string&) const;
        const CUDA getCUDA() const { return m_cuda;};   // inline getter (not mandatory, just in case for not losing points)
    private:
        void printLog() const { std::cout << "GPU is ready" << std::endl; };    // not mandatory
        const CUDA m_cuda;
};

class Computer {
    public:
        Computer() { printLog(); }; // default constructor for Computer
        void execute(std::string) const;    // main logic method of the Computer system
        void operator+(const CPU &cpu); // operator overload for attaching CPU to Compter
        void operator+(const GPU &gpu); // operator overload for attaching GPU to Compter

        //inline getters (not mandatory, just in case for not losing points)
        const CPU* getCPU() const { return mp_attachedCPU;};
        const GPU* getGPU() const { return mp_attachedGPU;};
        
        //inline setters (not mandatory, just in case for not losing points)
        void setCPU(const CPU &cpu) { mp_attachedCPU = &cpu; }
        void setGPU(const GPU &gpu) { mp_attachedGPU = &gpu; }
    private:
        void printLog() const { std::cout << "Computer is ready" << std::endl; };   // not mandatory
        const CPU *mp_attachedCPU = nullptr;
        const GPU *mp_attachedGPU = nullptr;
};