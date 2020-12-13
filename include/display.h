/**
 @File display.h
 @Brief Functions that can be used to output to display. Primarily for streamlining display output and ease of coding
 @Author Ben Roberts
 @Assignment Final Project
 @Date 12/9/2020
 */

#ifndef display_h
#define display_h

#include "console.h"
#include "commonFunctions.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

/**
 @Name welcome
 @Brief Outputs the welcome text present on the main screen
 @Author Ben Roberts
 @Date 12/9/2020
 */
void welcome();

/**
 @Name seperateScreen
 @Brief A line of dashes meant to seperate the screen so that confusion is cut down on from the user
 @Author Ben Roberts
 @Date 12/9/2020
 @Param newScreen defaults to true, is a bool that determines if there should be a long series of new lines to further seperate the screen
 */
void seperateScreen(bool newScreen = true);

/**
 @Name multiChoiceMenu
 @Brief Displays a menu of multiple choices for the user to answer from
 @Author Ben Roberts
 @Date 12/9/2020
 @Param opts options for the menu to display
 @Return an int with the value chosen
 */
int multiChoiceMenu(std::stringstream& opts);

/**
 @Name rangedUserInput
 @Brief A line of dashes meant to seperate the screen so that confusion is cut down on from the user
 @Author Ben Roberts
 @Date 12/9/2020
 @param min minimum number the user is allowed to input
 @param max maximum number the suer is allowed to input
 @return The int the user has chosen
 */
int rangedUserInput(int min, int max);

/**
 @Name displayTable
 @Brief Displays the CSV table
 @Author Ben Roberts
 @Date 12/9/2020
 @Param table The table which to format.
 */
void displayTable(std::vector<std::vector<std::string>> table);

/**
 @Name multiChoiceMenuTable
 @Brief A mult-choice menu with the table appended at the beginning
 @Author Ben Roberts
 @Date 12/10/2020
 @Param table Table to use
 @Param extraOpts Extra options for the user to choose from
 @Param numberFolders A bool telling the function if it should number folders when it is generating the output. This limits the user's input to include folders
 @Param numberComps A bool telling the function if it should number computers when it is generating the output. This limits the user's input to include computers
 */
std::string multiChoiceMenuTable(std::vector<std::vector<std::string>> table, std::stringstream& extraOpts, bool numberFolders = false, bool numberComps = false);

/**
 @Name promptYN
 @Brief Prompts the user for a yes or no to a question
 @Author Ben Roberts
 @Date 12/10/2020
 @Param question The question to ask the user
 @Return A bool that contains the user's answer
 */
bool promptYN(std::string question);

#endif /* display_h */
