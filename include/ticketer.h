/**
 @File commenter.h
 @Brief Contains the functions for controlling the commenting option from the main menu
 @Author Ben Roberts
 @Assignment Final Project
 @Date 12/10/2020
 */

#ifndef ticketer_h
#define ticketer_h

#include "display.h"
#include "editor.h" //Grabbing a couple editing functions

/**
 @Name ticketer
 @Brief Allows navigation of the data structure with access to writing comments and status changes
 @Author Ben Roberts
 @Date 12/11/2020
 @param log the log to store content to
 @param fileName the file which to read from
 */

void ticketer(Console& log, std::string fileName);

#endif /* ticketer_h */
