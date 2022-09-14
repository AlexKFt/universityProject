#include <fstream>
#include <string>
#include <sstream>
#include "CompressorStation.hpp"
#include <limits>
#include <iostream>




void createCompressorStation(CompressorStation& station)
{
    fillStationNameFor(station);
    fillWorkshopsNumberFor(station);
    fillActiveWorkshopsNumberFor(station);
    setEfficiencyTo(station);
}

void fillStationNameFor(CompressorStation& station)
{
    std::cout << "Enter station name: ";
    std::cin >> station.name;
    clearCsInputBuffer();
}

void clearCsInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void fillWorkshopsNumberFor(CompressorStation& station)
{
    std::cout << "Enter number of workshops: ";

    int input;
    for(;;)
    {
        if ((std::cin >> input).good() && (input > 0))  
        {
            station.numberOfWorkshops = input;
            clearCsInputBuffer();
            break;
        }
            
        else if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Error. There should be a number!\n";
        }else
        {
            std::cout << "Enter positive value\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


void fillActiveWorkshopsNumberFor(CompressorStation& station)
{
    std::cout << "Enter number of active workshops: ";

    int input;
    for(;;)
    {
        if ((std::cin >> input).good() && (input >= 0) && (input <= station.numberOfWorkshops))  
        {
            station.numberOfActiveWorkshops = input;
            clearCsInputBuffer();
            break;
        }       
        else if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Error. There should be a number!\n";
        }else if(input < 0)
        {
            std::cout << "Enter positive value\n";
        }
        else
        {
            std::cout << "Max number - " <<station.numberOfWorkshops << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }    
}

void setEfficiencyTo(CompressorStation& station)
{
    std::cout << "Enter station's rate: " << std::endl;

    int input;
    for(;;)
    {
        if ((std::cin >> input).good() && (input >= 0) && (input <= 100))  
        {
            station.perfomRateZeroToHundred = input;
            clearCsInputBuffer();
            break;
        }
        else if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Ошибка ввода. Введите число!\n";
        }else
        {
            std::cout << " Введите значение из интервала от 0 до 100\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


void activateWorkshopAt(CompressorStation& station)
{   
    if (freeWorkshopExistAt(station))
        station.numberOfActiveWorkshops++;
}

bool freeWorkshopExistAt(CompressorStation& station)
{
    return station.numberOfWorkshops > station.numberOfActiveWorkshops;
}

void StopWorkshopAt(CompressorStation& station)
{
    if (activeWorkshopLeftAt(station))
    station.numberOfActiveWorkshops--;
}

bool activeWorkshopLeftAt(CompressorStation& station)
{
    return station.numberOfActiveWorkshops > 0;
}


void print(CompressorStation& station)
{
    std::cout << "name: " << station.name << std::endl;
    std::cout << "number of workshops: "<< station.numberOfWorkshops << std::endl;
    std::cout << "number of active workshops: " << station.numberOfActiveWorkshops << std::endl;
    std::cout << "station efficiency: " << station.perfomRateZeroToHundred << std::endl;
}

void writeInFile(CompressorStation& station)
{
    std::ofstream fout;
    std::string fileName;

    while (!fout.is_open()) // !!! FIXME check the existance of file 
    {
        std::cout << "Enter the name of file: ";
        std::cin >> fileName;
        clearCsInputBuffer();
        fout.open(fileName, std::ios::app);
    }
    fout << station.name << ' ' 
         << station.numberOfWorkshops << ' ' 
         << station.numberOfActiveWorkshops << ' ' 
         << station.perfomRateZeroToHundred << '\n';

    fout.close();
}

void readFromFileIn(CompressorStation& station)
{
    std::ifstream fin;
    std::string fileName;
    std::string content;
    std::stringstream buffer;

    while (!fin.is_open())
    {
        std::cout << "Enter the name of file: ";
        std::cin >> fileName;
        clearCsInputBuffer();
        fin.open(fileName);
    }
    getline(fin, content); 
    buffer << content; 
    buffer >> station.name >> station.numberOfWorkshops 
           >> station.numberOfActiveWorkshops >> station.perfomRateZeroToHundred;
    fin.close();
}
