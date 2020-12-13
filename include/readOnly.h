/**
 @File readOnly.h
 @Brief Contains the function for controlling the readOnly option from the main menu
 @Author Ben Roberts
 @Assignment Final Project
 @Date 12/9/2020
 */

#ifndef readOnly_h
#define readOnly_h

#include "display.h"


/**
 @Name readOnly
 @Brief Allows navigation of the data structure without access to writing (good for preventing mistakes from the user)
 @Author Ben Roberts
 @Date 12/9/2020
 @param log the log to store content to
 @param fileName the file which to read from
 */
void readOnly(Console& log, std::string fileName);
#endif /* readOnly_h */
