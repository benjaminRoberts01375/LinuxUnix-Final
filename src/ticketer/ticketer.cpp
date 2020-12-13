#include "ticketer.h"

void ticketer(Console& log, std::string fileName)
{
    fileName = checkExt(fileName, ".csv");
    
    bool exit = false;
    while (!exit)
    {
        log.log("Opened ticketing view of \"" + fileName + "\".", "User");
        seperateScreen();
        log.displayLog();
        seperateScreen(false);
        try
        {
            auto CSVTable = readCSV(fileName, log);
            
            std::cout << "Ticketing view: " << fileName << std::endl << std::endl;
            
            std::stringstream choices;
            choices << "Modify computer status" << std::endl;
            choices << "Modify computer comment" << std::endl;
            choices << "Back";
            
            std::string choice = multiChoiceMenuTable(CSVTable, choices, true);
            if (choice == "Modify computer status")
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
                ticketer(log, checkExt(choice, ".csv"));
            }
        }
        catch (std::string e)
        {
            log.log(e, "Error");
        }
    }
}
