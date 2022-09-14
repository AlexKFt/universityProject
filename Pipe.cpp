#include <iostream>
#include <fstream>
#include <sstream>
#include "Pipe.hpp"
#include <limits>



void createPipe(Pipe& pipe)
{
    defineLengthImMetresFor(pipe);
    defineDiameterInMetresFor(pipe);
    defineRepairConditionFor(pipe);
}

void defineLengthImMetresFor(Pipe& pipe)
{
    std::cout << "Enter length of pipe in metres: ";
    pipe.lengthInMetres = positiveFloatInput();
}

void defineDiameterInMetresFor(Pipe& pipe)
{
    std::cout << "Enter diameter of pipe in metres: ";
    pipe.diameterInMetres = positiveFloatInput();
}

float positiveFloatInput()
{
    float input;
    for(;;)
    {
        if ((std::cin >> input).good() && (input > 0))  
        {
            clearPipeInputBuffer();
            return input;
        }            
        else if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Error. There should be a number!\n";
        }
        else
        {
            std::cout << "Enter positive value\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void clearPipeInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void defineRepairConditionFor(Pipe& pipe)
{
    std::cout << "Is pipe undere repair? ";
    std::cin >> pipe.isUnderRepair;
    clearPipeInputBuffer();
}

void print(Pipe& pipe)
{
    std::cout << "Length of pipe: " << pipe.lengthInMetres << std::endl;
    std::cout << "Diameter of pipe: " << pipe.diameterInMetres << std::endl;
    std::cout << "Is under repair: " << std::boolalpha << pipe.isUnderRepair << std::endl;
}

void setRepairConditionTo(Pipe& pipe, bool status)
{
    pipe.isUnderRepair = status;
}

void writeInFile(Pipe& pipe)
{
    std::ofstream fout;
    std::string fileName;

    while (!fout.is_open())
    {
        std::cout << "Enter the name of file: ";
        std::cin >> fileName;
        clearPipeInputBuffer();
        fout.open(fileName, std::ios::app);
    }

    fout << pipe.lengthInMetres << ' ' 
         << pipe.diameterInMetres << ' ' 
         << pipe.isUnderRepair << '\n';

    fout.close();
}

void readFromFileIn(Pipe& pipe)
{
    std::ifstream fin;
    std::string fileName;
    std::string content;
    std::stringstream buffer;

    while (!fin.is_open())
    {
        std::cout << "Enter the name of file: ";
        std::cin >> fileName;
        clearPipeInputBuffer();
        fin.open(fileName);
    }

    getline(fin, content);
    buffer << content;
    buffer >> pipe.lengthInMetres >> pipe.diameterInMetres >> pipe.isUnderRepair;
    fin.close();
    
}