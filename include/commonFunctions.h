/**
 @File commonFunctions.h
 @Brief Functions that are commonly used throughout the program, such as dealing with user input
 @Author Ben Roberts
 @Assignment Final Project
 @Date 12/9/2020
 */

#ifndef commonFunctions_h
#define commonFunctions_h

#include "console.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/**
 @Name readCSV
 @Brief Reads and parses CSV files to be in a 2D array. NOTE: ONLY USE WITH A TRY STATEMENT
 @Author Ben Roberts
 @Date 12/9/2020
 @Param fileName name of CSV file to read
 @Param log output for logging
 @Return 2D vector of strings which made up the CSV file
 */
std::vector<std::vector<std::string>> readCSV(std::string fileName, Console& log);

/**
 @Name isDigit
 @Brief Checks to make sure that a string only has numbers (0123456789)
 @Author Ben Roberts
 @Date 12/10/2020
 @Param text text to check
 @Return a bool, true = is only digits, false = is not just digits
 */
bool isDigit(std::string text);

/**
 @Name checkExt
 @Brief Checks to see if the final four characters match a provided extension (without the dot), ex: Passed "txt", and will check for ".txt"
 @Author Ben Roberts
 @Date 12/10/2020
 @Param name Name to check for an extension
 @Param ext Extension to check
 @Return A string with the extension added if needed.
 */
std::string checkExt(std::string name, std::string ext);

/**
 @Name saveCSV
 @Brief Given a table and file name, will save the table to the provided file
 @Author Ben Roberts
 @Date 12/11/2020
 @Param table The table to save
 @Param fileName Name of the file to save
 @Param log log to log with
 */
void saveCSV(std::vector<std::vector<std::string>> table, std::string fileName, Console& log);

#endif /* commonFunctions_h */
