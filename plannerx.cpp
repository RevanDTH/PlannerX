// IMPORTANT: This is the Windows version of the source code. If you want the linux version, check out the other source file in this repository :)


#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <map>
#include <list>
#include <limits>

//global variables
std::map<int, std::string> tasklist = {};
LPCSTR saveFilePath = "C:\\ProgramData\\PlannerX"; 
LPCSTR saveFile = "C:\\ProgramData\\PlannerX\\savefile.plx"; 
LPCSTR exePath = "C:\\Program Files (x86)\\PlannerX\\plannerx.exe";


void setup(){
    using namespace std;

    cout << "Welcome to the Setup of PlannerX." << endl;
    cout << "Press [ENTER] to continue with the setup or press [ctrl] + [c] to abort this action." << endl;
    cin.get();
    system("cls");

    cout << "Moving executable to " << exePath << endl;

    char currentExePathBuf[MAX_PATH];
    DWORD pathLen = GetModuleFileNameA(NULL, currentExePathBuf, MAX_PATH);
    if (pathLen == 0) {
        std::cout << "Failed to get current executable path. Error: " << GetLastError() << std::endl;
    } else {
        std::cout << "Current executable: " << currentExePathBuf << std::endl;
    }
    MoveFileA(currentExePathBuf,exePath);


    cout << "Creating directory for your savefile under " << saveFilePath << " . . ." << endl;
    if (!CreateDirectoryA(saveFilePath,NULL))
    {
        cout << "Failed to create directory!" << endl;
        return;
    }

    cout << "Directory created!" << endl;
    cout << "Creating savefile . . ." << endl;

    HANDLE hFile = CreateFileA(saveFile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        cout << "Failed to create savefile! Error: " << GetLastError() << endl;
    } else {
        cout << "Savefile created!" << endl;
        CloseHandle(hFile);
    }

    string exePathStr = exePath;
    size_t pos = exePathStr.find_last_of("\\/");
    if (pos != string::npos) {
        string dir = exePathStr.substr(0, pos);
        string cmd = "setx PATH \"%PATH%;" + dir + "\"";
        int res = system(cmd.c_str());
        if (res != 0) {
            cout << "Failed to update PATH. Command returned: " << res << endl;
        } else {
            cout << "PATH updated to include: " << dir << endl;
        }
    } else {
        cout << "Could not determine directory from exePath: " << exePathStr << endl;
    }

    

}

void loadTasks(){
    std::ifstream fileStream(saveFile);
    std::string line;
    while (std::getline(fileStream,line))
    {
        size_t pos = line.find(';');
        if (pos != std::string::npos) {
            std::string idStr = line.substr(0, pos);
            std::string taskStr = line.substr(pos + 1);

            // trim helper
            auto trim = [](std::string &s) {
                const char* ws = " \t\n\r\f\v";
                s.erase(0, s.find_first_not_of(ws));
                s.erase(s.find_last_not_of(ws) + 1);
            };

            trim(idStr);
            trim(taskStr);

            try {
                int id = std::stoi(idStr);
                tasklist[id] = taskStr;
            } catch (...) {
                std::cout << "Your tasklist is corrupted, please reinstall PlannerX by using the -setup argument on excution!" << std::endl;
            }
        }
    }
    
}

void saveTasks(){
    std::ofstream fileStream(saveFile);
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open savefile for writing: " << saveFile << std::endl;
        return;
    }

    for (const auto& entry : tasklist)
    {
        fileStream << entry.first << ";" << entry.second << "\n";
    }

    fileStream.close();
}

void createTask(std::string taskName){
    using namespace std;

    int highestID = 0;
    for (const auto& entry : tasklist) {
        if (entry.first > highestID)
            highestID = entry.first;
    }

    int newID = highestID + 1;

    tasklist[newID] = taskName;
}


void solveTask(int taskID){
    tasklist.erase(taskID);
}

bool hasArgument(int argc, char const* argv[], const std::string& name)
{
    for (int i = 1; i < argc; ++i)
        if (argv[i] == name)
            return true;
    return false;
}



int main(int argc, char const *argv[])
{

    if(hasArgument(argc,argv,"-setup")){
        setup();
        exit(0);
    }

    loadTasks();

    using namespace std;
    system("cls");

    int userChoice;

    while (true)
    {
        system("cls");

        cout << R"(
        /$$$$$$$  /$$                                                  /$$   /$$
        | $$__  $$| $$                                                 | $$  / $$
        | $$  \ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$|  $$/ $$/
        | $$$$$$$/| $$ |____  $$| $$__  $$| $$__  $$ /$$__  $$ /$$__  $$\  $$$$/ 
        | $$____/ | $$  /$$$$$$$| $$  \ $$| $$  \ $$| $$$$$$$$| $$  \__/ >$$  $$ 
        | $$      | $$ /$$__  $$| $$  | $$| $$  | $$| $$_____/| $$      /$$/\  $$
        | $$      | $$|  $$$$$$$| $$  | $$| $$  | $$|  $$$$$$$| $$     | $$  \ $$
        |__/      |__/ \_______/|__/  |__/|__/  |__/ \_______/|__/     |__/  |__/                                                                    
        )" << endl << endl << endl;
        
        cout << "------------------------------- Tasks -------------------------------" << endl;
        for(const auto& task : tasklist){
            cout << "(" << std::to_string(task.first) << ") " << task.second << endl << endl;
        }
        cout << "---------------------------------------------------------------------" << endl << endl;

        cout << "[1] Create task" << endl;
        cout << "[2] Solve task" << endl;
        cout << "[3] Exit" << endl;
        cout << ": ";
        if(cin >> userChoice){
            string newTaskName;
            switch (userChoice)
            {
            case 1:
                system("cls");
                cout << "Name of the Task: ";
                getline(std::cin >> std::ws, newTaskName);
                createTask(newTaskName);
                break;

            case 2:
                system("cls");
                int taskID;
                for(const auto& task : tasklist){
                    cout << "(" << std::to_string(task.first) << ") " << task.second << endl << endl;
                }
                cout << "ID of the Task: ";
                cin >> taskID;
                solveTask(taskID);
                break;
            case 3:
                saveTasks();
                exit(0);
            default:
                break;
            }
        }else
        {
            cin.clear();
            continue;
        }
        

    }
    



    return 0;
}
