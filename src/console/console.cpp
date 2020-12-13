#include "console.h"
void Console::log(std::string text, std::string info, bool number)
{
    std::stringstream fileLabel, label, fileCompiled, compiled;
    
    fileOutput.seekg(0, std::ios::end); //Ensure at end of file
    lines++;
    consoleLines++;
    
    if (number == true)
    {
        if (lines < 10)
        {
            fileLabel << "00" << lines;
        }
        else if (lines > 9 && lines < 100)
        {
            fileLabel << "0" << lines;
        }
        else
        {
            fileLabel  << lines;
        }
        
        if (consoleLines < 10)
        {
            label << "00" << consoleLines;
        }
        else if (consoleLines > 9 && consoleLines < 100)
        {
            label << "0" << consoleLines;
        }
        else
        {
            label << consoleLines;
        }
    }
    
    if (info != "" && number)
    {
        label << " -> " + info;
        fileLabel << " -> " + info;
    }
    else if (info != "")
    {
        label << info;
        fileLabel << info;
    }
    
    compiled << std::endl;
    fileCompiled << std::endl;
    
    if (label.str() != "")
    {
        compiled << "[" << label.str() << "] ";
        fileCompiled << "[" << fileLabel.str() << "] ";
    }
     
    compiled << text;
    fileCompiled << text;
    history << compiled.str(); //Console output
    fileOutput << fileCompiled.str(); //File output
}

Console::Console()
{
    try
    {
        fileOpener();
    }
    catch (std::string e)
    {
        fileOutput.open(logFile, std::ios::app | std::ios::in | std::ios::out);
        log(e, "Error");
    }
}

void Console::fileOpener()
{
    fileOutput.open(logFile, std::ios::ate | std::ios::in | std::ios::out);
    
    if (fileOutput.fail()) //Could not log open file
    {
        std::string error = "Failed to open log file. Creating a new one.";
        throw error;
    }
    else //Log file found and opened
    {
        std::string seperator;
        const int SEPERATOR_LENGTH = 100;
        seperator.append(SEPERATOR_LENGTH, '-');
        
        std::string junk;
        fileOutput.seekg(0, std::ios::beg);
        while (!fileOutput.eof()){ //Count lines
            getline(fileOutput, junk);
            if (junk.length() > 1)
            {
                if (junk.at(0) == '[')
                 lines++;
            }
        }
        lines--;
        
        log(seperator, "", false); //For seperating old logs and new logs
        log("Log file opened.", "System");
    }
}

void Console::consoleState(bool state)
{
    display = state;
}

void Console::displayLog()
{
    if (display)
    {
        std::cout << getLog() << std::endl;
    }
}
