#include "commonFunctions.h"

std::vector<std::vector<std::string>> readCSV(std::string fileName, Console& log)
{
    fileName = checkExt(fileName, ".csv");
    log.log("Attempting to open file \"" + fileName + "\".", "System");
    std::vector<std::vector<std::string>> parsed; //Where the CSV file is imported
    std::ifstream CSVFile;
    CSVFile.open(fileName, std::ios::in);
    if (CSVFile.good()) //File is opened
    {
        log.log("Successfully opened \"" + fileName + "\".", "System");
        std::string headers;
        getline(CSVFile, headers);
        
        while (!CSVFile.eof()) //Keep reading file until end
        {
            std::string type, name, status, comment;
            getline(CSVFile, type, ','); //Type
            getline(CSVFile, name, ','); //name
            getline(CSVFile, status, ','); //status
            getline(CSVFile, comment); //comment
            
            std::vector<std::string> line = {type, name, status, comment};
            parsed.push_back(line);
        }
    }
    else //Not able to open file
    {
        std::string e = "Unable to open file \"" + fileName + "\".";
        throw e;
    }
    
    CSVFile.close();
    
    return parsed;
}

bool isDigit(std::string text)
{
    bool isDigits = true;
    
    for (int i = 0; i < text.length() && isDigits; i++)
    {
        if (text.at(i) != '1' && text.at(i) != '2' && text.at(i) != '3' && text.at(i) != '4' && text.at(i) != '5' && text.at(i) != '6' && text.at(i) != '7' && text.at(i) != '8' && text.at(i) != '9' && text.at(i) != '0') //If it's not a digit, then the function is set to false
        {
            isDigits = false;
        }
    }
    
    return isDigits;
}

std::string checkExt(std::string name, std::string ext)
{
    if (name.length() > ext.length()) //Protection in the event that the name is less than 4 chars
    {
        if (name.substr(name.length() - ext.length(), ext.length()) != ext)
        {
            name += ext;
        }
    }
    else
    {
        name += ext;
    }
    return name;
}

void saveCSV(std::vector<std::vector<std::string>> table, std::string fileName, Console& log)
{
    log.log("Attempting to save file \"" + fileName + "\".", "System");
    std::ofstream saveFile;
    saveFile.open(fileName, std::ios::trunc);
    
    if (saveFile.good())
    {
        saveFile << "Type,Name,Status,Comment" << std::endl;
        for (int i = 0; i < table.size(); i++)
        {
            for (int j = 0; j < table[i].size() - 1; j++)
            {
                saveFile << table[i][j] << ",";
            }
            saveFile << table[i][table[i].size()-1];
            saveFile << std::endl;
        }
        log.log("Successfully saved \"" + fileName + "\"", "System");
    }
    else
    {
        log.log("Could not open file to save.", "System");
    }
}
