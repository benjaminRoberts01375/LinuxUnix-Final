#include "display.h"

void welcome()
{
    std::cout << std::setw(100) << std::right << "Welcome to The Champlain College Computer Ticketing System v2" << std::endl;
}

void seperateScreen(bool newScreen)
{
    if (newScreen)
    {
        const int NEW_SCREEN_HEIGHT = 50;
        for (int i = 0; i < NEW_SCREEN_HEIGHT; i++)
        {
            std::cout << std::endl;
        }
    }
 
    std::string dash;
    const int DASH_LENGTH = 100;
    dash.append(DASH_LENGTH, '-');
    std::cout << dash << std::endl;
}

int multiChoiceMenu(std::stringstream& opts)
{
    int optNum = 0;
    while (!opts.eof())
    {
        std::string menuOpt;
        std::getline(opts, menuOpt);
        std::cout << "[" << ++optNum << "] " << menuOpt << std::endl;
    }

    return rangedUserInput(1, optNum);
}

int rangedUserInput(int min, int max)
{
    bool goodInput = false;
    int choice;
    
    while(!goodInput)
    {
        std::string strChoice;
        
        std::cout << "(" << min << "-" << max << "): "; //Function output
        std::cin >> strChoice;
        
        if (isDigit(strChoice))
        {
            choice = stoi(strChoice);
            
            if (choice >= min && choice <= max) //Only leave the function when a valid option is given
            {
                goodInput = true;
            }
        }
    }
    
    return choice; //There may be a warning here about choice not being initialized, it will be since the user cannot escape the while loop until it is
}


void displayTable(std::vector<std::vector<std::string>> table)
{
    int typeMaxLen = 4, nameMaxLen = 4; //4 is default since "name", "type" are 4 characters long
    int statusMaxLen = 6; //6 is default since "status" is 6 characters long
    int commentMaxLen = 7; //7 is defualt since "comment" is 7 characters long

    for (int i = 0; i < table.size(); i++) //Determine the max length of all the cells
    {
        if (table[i][0].length() > typeMaxLen)
        {
            typeMaxLen = table[i][0].length();
        }
        if (table[i][1].length() > nameMaxLen)
        {
            nameMaxLen = table[i][1].length();
        }
        if (table[i][2].length() > statusMaxLen)
        {
            statusMaxLen = table[i][2].length();
        }
        if (table[i][3].length() > commentMaxLen)
        {
            commentMaxLen = table[i][3].length();
        }
    }

    std::cout << std::setw(typeMaxLen) << std::right << "Type" << std::setw(1) << " ┃ " << std::setw(nameMaxLen) << std::left << "Name" << std::setw(1) << " ┃ " << std::setw(statusMaxLen) << std::left << "Status" << std::setw(1) << " ┃ " << "Comment" << std::endl; //Headers

    for (int j = 0; j < table.size(); j++) //Run for each row
    {
        for (int i = 0; i < typeMaxLen; i++) //Line seperators for type
        {
            std::cout << "━";
        }

        std::cout << "━╋━";

        for (int i = 0; i < nameMaxLen; i++) //Line seperators for name
        {
            std::cout << "━";
        }

        std::cout << "━╋━";

        for (int i = 0; i < statusMaxLen; i++) //Line seperators for status
        {
            std::cout << "━";
        }

        std::cout << "━╋━";

        for (int i = 0; i < commentMaxLen; i++) //Line seperators for comment
        {
            std::cout << "━";
        }

        std::cout << std::endl;
        std::cout << std::setw(typeMaxLen) << std::right << table[j][0] << std::setw(1) << " ┃ " << std::setw(nameMaxLen) << std::left << table[j][1] << std::setw(1) << " ┃ " << std::setw(statusMaxLen) << std::left << table[j][2] << std::setw(1) << " ┃ " << table[j][3]; //Table Data
        std::cout << std::endl;
    }
}

std::string multiChoiceMenuTable(std::vector<std::vector<std::string>> table, std::stringstream& extraOpts, bool numberFolders, bool numberComps)
{
    int index = 0;
    
    //Table formatting
    int typeMaxLen = 4, nameMaxLen = 4; //4 is default since "name", "type" are 4 characters long
    int statusMaxLen = 6; //6 is default since "status" is 6 characters long
    int commentMaxLen = 7; //7 is defualt since "comment" is 7 characters long
    
    for (int i = 0; i < table.size(); i++) //Determine the max length of all the cells
    {
        if (table[i][0].length() > typeMaxLen)
        {
            typeMaxLen = table[i][0].length(); //May have a warning, it's fine
        }
        if (table[i][1].length() > nameMaxLen)
        {
            nameMaxLen = table[i][1].length(); //May have a warning, it's fine
        }
        if (table[i][2].length() > statusMaxLen)
        {
            statusMaxLen = table[i][2].length(); //May have a warning, it's fine
        }
        if (table[i][3].length() > commentMaxLen)
        {
            commentMaxLen = table[i][3].length(); //May have a warning, it's fine
        }
    }
    
    const int NUMBER_SPACE = 5;
    std::cout << std::setw(NUMBER_SPACE) << "" << std::setw(typeMaxLen) << std::right << "Type" << std::setw(1) << " ┃ " << std::setw(nameMaxLen) << std::left << "Name" << std::setw(1) << " ┃ " << std::setw(statusMaxLen) << std::left << "Status" << std::setw(1) << " ┃ " << "Comment" << std::endl; //Headers

    std::vector<std::string> opts;
    //Drawing table
    for (int j = 0; j < table.size(); j++)
    {
        for (int i = 0; i < NUMBER_SPACE; i++)
        {
            std::cout << "━";
        }
        for (int i = 0; i < typeMaxLen; i++) //Line seperators for type
        {
            std::cout << "━";
        }
        
        std::cout << "━╋━";
        
        for (int i = 0; i < nameMaxLen; i++) //Line seperators for name
        {
            std::cout << "━";
        }
        
        std::cout << "━╋━";
        
        for (int i = 0; i < statusMaxLen; i++) //Line seperators for status
        {
            std::cout << "━";
        }
        
        std::cout << "━╋━";
        
        for (int i = 0; i < commentMaxLen; i++) //Line seperators for comment
        {
            std::cout << "━";
        }
        
        std::cout << std::endl;
        
        //Output number for choice
        if ((numberFolders && table[j][0] == "Folder") || (numberComps && table[j][0] == "Computer")) //Computers and/or folders are enabled
        {
            index++;
            std::cout << std::setw(NUMBER_SPACE) << std::right << "[" + std::to_string(index) + "]";
            opts.push_back(table[j][1]);
        }
        else
        {
            std::cout << std::setw(NUMBER_SPACE) << std::right << " ";
        }
        std::cout << std::setw(typeMaxLen) << std::right << table[j][0] << std::setw(1) << " ┃ " << std::setw(nameMaxLen) << std::left << table[j][1] << std::setw(1);
        
        if (table[j][0] == "Computer") //Hiding the status and comment for a folder since file names are stored in the comments
        {
            std::cout << " ┃ " << std::setw(statusMaxLen) << std::left << table[j][2] << std::setw(1) << " ┃ " << table[j][3]; //Table Data
        }
        else
        {
            std::cout << " ┃ " << std::setw(statusMaxLen) << std::left << "" << std::setw(1) << " ┃ " << ""; //Blank table data
        }
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    
    while (!extraOpts.eof())
    {
        std::string menuOpt;
        std::getline(extraOpts, menuOpt);
        std::cout << std::setw(NUMBER_SPACE) << std::right << ("[" + std::to_string(++index) + "]") << " " << menuOpt;
        opts.push_back(menuOpt);
    }
    
    std::cout << std::endl;
    
    return opts[rangedUserInput(1, index) - 1];
}

bool promptYN(std::string question)
{
    bool answer = false;
    bool answered = false;
    
    while (!answered)
    {
        std::cout << question << std::endl;
        std::cout << "(Y/N): ";
        std::string strAnswer;
        std::cin >> strAnswer;
        
        if (strAnswer == "Y" || strAnswer == "y" || strAnswer == "yes" || strAnswer == "YES")
        {
            answered = true;
            answer = true;
        }
        else if (strAnswer == "N" || strAnswer == "n" || strAnswer == "no" || strAnswer == "NO")
        {
            answered = true;
            answer = false;
        }
        else
        {
            std::cout << "Error, answer invalid." << std::endl;
        }
    }
    
    return answer;
}
