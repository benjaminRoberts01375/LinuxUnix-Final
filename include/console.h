#ifndef console_h
#define console_h

/**
 @File console.h
 @Brief Functions for the console to input and output
 @Author Ben Roberts
 @Assignment Final Project
 @Date 12/9/2020
 */

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

/**
 @Class Keeps track of the output console
 @Brief Linked list for maintaining channel data
 @Author Ben Roberts
 @Date 12/9/2020
 */

class Console{
private:
    std::string logFile = "output.txt";
    std::stringstream history; //Console output
    std::fstream fileOutput; //File output
    int lines = 0;
    int consoleLines = -1; //These aren't saved on close. Starts at -1 to offset the spacer
    bool display = false; //Determines if the console should output to the screen or not
    
    /**
     @Name fileOpener
     @Brief Attempts to open the log file for the Console object, and sets lines (skips seperators) . Only called once. This must exist because this is a log, which uses an output file.
     @Author Ben Roberts
     @Date 12/9/2020
     */
    void fileOpener();
public:    
    /**
     @Name getLog
     @Brief Retrieves the log from the variable
     @Author Ben Roberts
     @Date 12/9/2020
     */
    std::string getLog(){ return history.str(); }
    
    /**
     @Name log
     @Brief 1. Adds on to end of variable. 2. Outputs text variable to output file. 3. Updates line variable by 1
     @Author Ben Roberts
     @Date 12/9/2020
     @param text : Text to add to log
     @param number : True = new line in log will be numbered, False = new line in log will not be numbered
     @param info : Info about the incomming line (Ex. error, user input)
     */
    void log(std::string text, std::string info = "", bool number = true);
    
    /**
     @Name displayLog
     @Brief Ouputs the log to the console
     @Author Ben Roberts
     @Date 12/9/2020
     */
    void displayLog();
    
    /**
     @Name consoleState
     @Brief Allows for the toggeling of the console's output to screen
     @Author Ben Roberts
     @Date 12/10/2020
     @Param state Determines if the console ouput to the screen should be enabled or disabled
     */
    void consoleState(bool state = false);
    
    /**
     @Name Console
     @Brief Default constructor for console object
     @Author Ben Roberts
     @Date 12/9/2020
     */
    Console();
    
    /**
     @Name ~Console
     @Brief Destorys console object
     @Author Ben Rpberts
     @Date 12/9/2020
     */
    ~Console(){};
};

#endif /* console_h */
