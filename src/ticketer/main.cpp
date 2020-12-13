/**
 @File main.cpp
 @Brief Driver file for rest of program
 @Author Ben Roberts
 @Assignment Final Project
 @Date 12/8/2020
 */

#include "console.h"

#include "display.h"
#include "readOnly.h"
#include "editor.h"
#include "ticketer.h"

#include <unistd.h>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
    Console log; //Create system log
    bool privileged = false;
    bool helpMode = false;
    std::string CSVFile = "";
    
    if (getuid() == 0) //Check if root
    {
        log.log("Program ran as privileged.", "User");
        privileged = true;
    }
    else
    {
        log.log("Program ran as normal user.", "User");
    }
    
    for (int i = 1; i < argc; i++) //Start at 1 to skip the directory. Checking for args passed
    {
        std::string arg = argv[i];
        if (arg == "-v")
        {
            log.consoleState(true);
        }
        else if (arg == "-o")
        {
            CSVFile = checkExt(argv[i+1], ".csv");
            i++;
            
            fstream passedFile;
            passedFile.open(CSVFile, ios::in);
            if (!passedFile.good())
            {
                log.log("Passed file does not exist in directory.", "Error");
                cout << "Error: Passed file does not exist in directory." << endl;
                EXIT_FAILURE;
            }
            
        }
        else if (arg == "-h")
        {
            helpMode = true;
        }
        else
        {
            log.log("\"" + arg + "\" is not supported. Use -h for help.", "Error");
            cout << "Error: \"" + arg + "\" is not supported. Use -h for help." << endl;
            return EXIT_FAILURE;
        }
    }
    
    if (helpMode)
    {
        std::cout << "-h    Displays help screen" << endl;
        std::cout << "-o    Passing a file to open." << endl;
        std::cout << "-v    Verbose mode, enables logging to the screen [RECOMMENDED]." << endl;
    }
    else
    {
        if (CSVFile == "")
        {
            const string DEFAULT_NAME = "base.csv";
            
            log.log("No CSV file was provided, starting with defaults.", "Error");
            fstream defaultStart;
            defaultStart.open(DEFAULT_NAME, ios::app); //Just to make the file
            defaultStart.close();
            CSVFile = DEFAULT_NAME;
        }
        
        bool run = true;
        while (run)
        {
            seperateScreen();
            log.log("Opened main menu.", "User");
            log.displayLog();
            seperateScreen(false);
            welcome();
            seperateScreen(false);
            //privileged = true;
            if (!privileged)
            {
                stringstream menuOpts;
                menuOpts << "Read-only view" << endl;
                menuOpts << "Submit/Edit ticket" << endl;
                menuOpts << "Exit";
                int menuOpt = multiChoiceMenu(menuOpts);
                
                if (menuOpt == 1)
                {
                    readOnly(log, CSVFile);
                }
                else if (menuOpt == 2)
                {
                    ticketer(log, CSVFile);
                }
                else if (menuOpt == 3)
                {
                    run = false;
                }
            }
            else
            {
                stringstream menuOpts;
                menuOpts << "Read-only view" << endl;
                menuOpts << "Make Edits/Resolve" << endl;
                menuOpts << "Exit";
                int menuOpt = multiChoiceMenu(menuOpts);
                
                if (menuOpt == 1)
                {
                    readOnly(log, CSVFile);
                }
                else if (menuOpt == 2)
                {
                    editor(log, CSVFile);
                }
                else if (menuOpt == 3)
                {
                    run = false;
                }
            }
        }
        
        log.log("Shutdown.", "User");
    }
    return EXIT_SUCCESS;
}
