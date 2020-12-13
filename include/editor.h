/**
 @File editor.h
 @Brief Contains the function for controlling the editor option from the main menu
 @Author Ben Roberts
 @Assignment Final Project
 @Date 12/10/2020
 */

#ifndef editor_h
#define editor_h

#include "display.h"
#include <stdio.h>

/**
 @Name readOnly
 @Brief Allows navigation of the data structure with access to reading, as well as writing (good for preventing mistakes from the user)
 @Author Ben Roberts
 @Date 12/10/2020
 @param log the log to store content to
 @param fileName the file which to read from
 */
void editor(Console& log, std::string fileName);

/**
 @Name createFolder
 @Brief Allows the user to create a new .csv file (in this program appears as a folder)
 @Author Ben Roberts
 @Date 12/10/2020
 @Param log the log to log with
 @Param table The table which is currently in use
 */
void createFolder(Console& log, std::vector<std::vector<std::string>>& table);

/**
 @Name createComputer
 @Brief Allows the user to create a new computer the currently open .csv file.
 @Author Ben Roberts
 @Date 12/10/2020
 @Param log the log to log with
 @Param table The table which is currently in use
 */
void createComputer(Console& log, std::vector<std::vector<std::string>>& table);

/**
 @Name deleteFolder
 @Brief Deletes the CSV file the user desires
 @Author Ben Roberts
 @Date 12/10/2020
 @Param log the log to log with
 @Param table The table in use
 */
void deleteFolder(Console& log, std::vector<std::vector<std::string>>& table);

/**
 @Name deleteComp
 @Brief Deletes a computer from thee CSV file
 @Author Ben Roberts
 @Date 12/11/2020
 @Param log the log to log with
 @Param table The table in use
 */
void deleteComp(Console& log, std::vector<std::vector<std::string>>& table);

/**
 @Name adjStatus
 @Brief Allows the user to adjust the status of a computer
 @Author Ben ROberts
 @Date 12/11/2020
 @Param log the log to log with
 @Param table The table to use
 */
void adjStats(Console& log, std::vector<std::vector<std::string>>& table);

/**
 @Name adjComment
 @Brief Allows the user to adjust the comment of a computer
 @Author Ben Roberts
 @Date 12/11/2020
 @Param log the log to log with
 @Param table The table to use
 */
void adjComment(Console& log, std::vector<std::vector<std::string>>& table);

#endif /* editor_h */
