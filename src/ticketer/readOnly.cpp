#include "readOnly.h"
#include "console.h"

void readOnly(Console& log, std::string fileName)
{
    fileName = checkExt(fileName, ".csv");
    
    bool exit = false;
    while (!exit)
    {
        log.log("Opened read-only view of \"" + fileName + "\".", "User");
        seperateScreen();
        log.displayLog();
        seperateScreen(false);
        try
        {
            auto CSVTable = readCSV(fileName, log);
            
            std::cout << "Read only view: " << fileName << std::endl << std::endl;
            
            std::stringstream choices;
            choices << "Back";
            
            std::string choice = multiChoiceMenuTable(CSVTable, choices, true);
            
            if (choice == "Back")
            {
                exit = true;
            }
            else
            {
                readOnly(log, checkExt(choice, ".csv"));
            }
        }
        catch (std::string e)
        {
            log.log(e, "Error");
        }
    }
}
