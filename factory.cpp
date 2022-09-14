#include <string>
#include <iostream>
#include "CompressorStation.hpp"
#include "Pipe.hpp"
#include "menu.hpp"



int main()
{  
    
    /*
    Pipe pipe1, pipe2;
    createPipe(pipe1);
    writeInFile(pipe1);
    readFromFileIn(pipe2);
    print(pipe1);
    print(pipe2);
    */
    CompressorStation fac1, fac2;
    createCompressorStation(fac1);
    print(fac1);
    writeInFile(fac1);
    readFromFileIn(fac2);
    print(fac2);

    return 0;
}

