#include "editor.h"

void editor(Console& log, std::string fileName)
{
    try
    {
        auto CSVTable = readCSV(fileName, log);
        
        fileName = checkExt(fileName, ".csv");
        
        bool exit = false;
        while (!exit)
        {
            log.log("Opened editing for \"" + fileName + "\".", "User");
            seperateScreen();
            log.displayLog();
            seperateScreen(false);
            
            std::cout << "Editing: " << fileName << std::endl << std::endl;
            
            std::stringstream choices;
            choices << "Create folder" << std::endl;
            choices << "Create computer" << std::endl;
            choices << "Delete folder" << std::endl;
            choices << "Delete computer" << std::endl;
            choices << "Modify computer status" << std::endl;
            choices << "Modify computer comment" << std::endl;
            choices << "Back";
            
            std::string choice = multiChoiceMenuTable(CSVTable, choices, true);
            
            if (choice == "Create folder")
            {
                createFolder(log, CSVTable);
                saveCSV(CSVTable, fileName, log);
            }
            else if (choice == "Create computer")
            {
                createComputer(log, CSVTable);
                saveCSV(CSVTable, fileName, log);
            }
            else if (choice == "Delete folder")
            {
                deleteFolder(log, CSVTable);
                saveCSV(CSVTable, fileName, log);
            }
            else if (choice == "Delete computer")
            {
                deleteComp(log, CSVTable);
                saveCSV(CSVTable, fileName, log);
            }
            else if (choice == "Modify computer status")
            {
                adjStats(log, CSVTable);
                saveCSV(CSVTable, fileName, log);
            }
            else if (choice == "Modify computer comment")
            {
                adjComment(log, CSVTable);
                saveCSV(CSVTable, fileName, log);
            }
            else if (choice == "Back")
            {
                exit = true;
            }
            else
            {
                editor(log, checkExt(choice, ".csv"));
            }
        }
    }
    catch (std::string e)
    {
        log.log(e, "Error");
    }
}

void createFolder(Console& log, std::vector<std::vector<std::string>>& table)
{
    seperateScreen();
    displayTable(table);
    std::cout << std::endl << std::endl;
    
    std::string folderName;
    bool goodName = false;
    std::string error = "";
    std::cin.ignore(10000, '\n');

    while(!goodName)
    {
        std::cout << error << std::endl;
        
        std::cout << "Name of new folder (no commas allowed): ";
        std::getline(std::cin, folderName);
        
        
        std::size_t found = folderName.find(','); //Code from http://www.cplusplus.com/reference/string/string/find/
        if (found == std::string::npos)
        {
            
            //Check if file already exists. If it can be opened, it exists
            std::fstream CSVFile;
            std::string fileName = checkExt(folderName, ".csv");
            CSVFile.open(fileName, std::ios::in);
            if (!CSVFile.good()) //File is unable to be opened, thus, does not exist
            {
                CSVFile.close();
                CSVFile.open(fileName, std::ios::app);
                log.log("Attempting to create the folder \"" + folderName + "\".", "System");
                
                if (!CSVFile.good()) //Unable to make file
                {
                    log.log("Could not create \"" + fileName + "\", aborting.", "Error");
                    error = "Could not create \"" + fileName + "\", aborting.";
                }
                else
                {
                    std::vector<std::string> temp = {"Folder", folderName, "", fileName};
                    table.push_back(temp);
                    goodName = true;
                }
            }
            else
            {
                error = "Error: File already exists in system.";
            }
        }
        else
        {
            error = "Error: No commas allowed.";
        }
    }
}

void createComputer(Console& log, std::vector<std::vector<std::string>>& table)
{
    seperateScreen();
    displayTable(table);
    std::cout << std::endl << std::endl;
    
    bool goodName = false;
    std::string error;
    std::string compName;
    while (!goodName)
    {
        std::cout << error << std::endl;
        std::cout << "Name of computer to add to this folder (no commas allowed): ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, compName);
        
        bool found = false;
        for (int i = 0; i < table.size() && !found; i++)
        {
            if (table[i][0] == "Computer" && table[i][1] == compName)
            {
                found = true;
                error = "Error: \"" + compName + "\" already exists in this folder.";
            }
        }
        if (!found)
        {
            std::size_t found = compName.find(','); //Code from http://www.cplusplus.com/reference/string/string/find/
            if (found == std::string::npos)
            {
                goodName = true;
                if (promptYN("Are you sure you want to create a computer with the name \"" + compName + "\"?"))
                {
                    log.log("Created computer named \"" + compName + "\".", "User");
                    std::vector<std::string> temp = {"Computer", compName, "Online", "My new computer"};
                    table.push_back(temp);
                }
            }
            else
            {
                std::cout << "Error: No commas allowed." << std::endl;
            }
        }
    }
}

void deleteFolder(Console& log, std::vector<std::vector<std::string>>& table)
{
    seperateScreen();
    displayTable(table);
    bool finished = false;
    std::string folderName, error = "";
    std::cout << std::endl << std::endl;
    std::cin.ignore(10000, '\n');
    
    while(!finished)
    {
        std::cout << error << std::endl;
        std::cout << "Folder to delete: ";
        std::getline(std::cin, folderName);
        
        bool exists = false;
        for (int i = 0; i < table.size() && !exists; i++)
        {
            if (table[i][0] == "Folder" && table[i][1] == folderName)
            {
                exists = true;
            }
        }
        if (exists)
        {
            if (promptYN("Are you sure you want to delete the folder \"" + folderName + "\"?"))
            {
                log.log("Attempting to delete folder \"" + folderName + "\".", "User");
                
                folderName = checkExt(folderName, ".csv");
                if ( std::remove(folderName.c_str()) == 0) //Tip on converting to cstring https://stackoverflow.com/questions/11821491/converting-string-to-cstring-in-c
                {
                    auto vecIterator = table.begin();
                    for (int i = 0; i < table.size(); i++)
                    {
                        std::string first = table[i][0];
                        std::string second = table[i][1];
                        
                        if (table[i][0] == "Folder" && checkExt(table[i][1], ".csv") == folderName)
                        {
                            table.erase(vecIterator);
                        }
                        else
                        {
                            vecIterator++;
                        }
                    }
                    
                    log.log("Successfully deleted \"" + folderName + "\".", "System");
                    finished = true;
                }
                else
                {
                    log.log("Failed to delete \"" + folderName + "\".");
                    error = "Failed to delete \"" + folderName + "\".";
                }
            }
        }
        else
        {
            error = "Error: Folder does not exist";
        }
    }
}

void deleteComp(Console& log, std::vector<std::vector<std::string>>& table)
{
    seperateScreen();
    displayTable(table);
    bool finished = false;
    std::string compName, error = "";
    std::cout << std::endl << std::endl;
    std::cin.ignore(10000, '\n');
    
    while(!finished)
    {
        std::cout << error << std::endl;
        std::cout << "Computer to delete: ";
        std::getline(std::cin, compName);
        
        bool exists = false;
        for (int i = 0; i < table.size() && !exists; i++)
        {
            if (table[i][0] == "Computer" && table[i][1] == compName)
            {
                exists = true;
            }
        }
        if (exists)
        {
            if (promptYN("Are you sure you want to delete the computer \"" + compName + "\"?"))
            {
                log.log("Attempting to delete computer \"" + compName + "\".", "User");
                auto vecIterator = table.begin();
                for (int i = 0; i < table.size(); i++)
                {
                    if (table[i][0] == "Computer" && table[i][1] == compName)
                    {
                        table.erase(vecIterator);
                    }
                    else
                    {
                        vecIterator++;
                    }
                }
                
                log.log("Successfully deleted \"" + compName + "\".", "System");
                finished = true;
            }
        }
        else
        {
            error = "Error: Computer does not exist";
        }
    }
}

void adjStats(Console& log, std::vector<std::vector<std::string>>& table)
{
    seperateScreen();
    displayTable(table);
    bool finished = false;
    std::string compName, error = "";
    std::cout << std::endl << std::endl;
    std::cin.ignore(10000, '\n');
    
    while(!finished)
    {
        std::cout << error << std::endl;
        std::cout << "Computer to adjust the status of: ";
        std::getline(std::cin, compName);
        
        bool exists = false;
        for (int i = 0; i < table.size() && !exists; i++)
        {
            if (table[i][0] == "Computer" && table[i][1] == compName)
            {
                exists = true;
            }
        }
        if (exists)
        {
            std::string newStatus;
            std::cout << "New status for \"" << compName << "\": ";
            std::getline(std::cin, newStatus);
            
            if (promptYN("Are you sure you want to change the status for computer \"" + compName + "\" to \"" + newStatus + "\"?"))
            {
                auto vecIterator = table.begin();
                for (int i = 0; i < table.size(); i++)
                {
                    if (table[i][0] == "Computer" && table[i][1] == compName)
                    {
                        log.log("Changed the computer \"" + compName + "\"'s status to \"" + newStatus + "\".", "User");
                        table[i][2] = newStatus;
                        finished = true;
                    }
                    else
                    {
                        vecIterator++;
                    }
                }
            }
        }
    }
}

void adjComment(Console& log, std::vector<std::vector<std::string>>& table)
{
    seperateScreen();
    displayTable(table);
    bool finished = false;
    std::string compName, error = "";
    std::cout << std::endl << std::endl;
    std::cin.ignore(10000, '\n');
    
    while(!finished)
    {
        std::cout << error << std::endl;
        std::cout << "Computer to adjust the comment of: ";
        std::getline(std::cin, compName);
        
        bool exists = false;
        for (int i = 0; i < table.size() && !exists; i++)
        {
            if (table[i][0] == "Computer" && table[i][1] == compName)
            {
                exists = true;
            }
        }
        if (exists)
        {
            std::string newComment;
            std::cout << "New comment for \"" << compName << "\": ";
            std::getline(std::cin, newComment);
            
            if (promptYN("Are you sure you want to change the comment for computer \"" + compName + "\" to \"" + newComment + "\"?"))
            {
                auto vecIterator = table.begin();
                for (int i = 0; i < table.size(); i++)
                {
                    if (table[i][0] == "Computer" && table[i][1] == compName)
                    {
                        log.log("Changed the computer \"" + compName + "\"'s comment to \"" + newComment + "\".", "User");
                        table[i][3] = newComment;
                        finished = true;
                    }
                    else
                    {
                        vecIterator++;
                    }
                }
            }
        }
    }
}
