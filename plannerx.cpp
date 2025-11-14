// IMPORTANT: This is the Windows version of the source code. If you want the linux version, check out the other source file in this repository :)


#include <iostream>
#include <string>
#include <Windows.h>

void setup(){
    using namespace std;

    LPCSTR saveFilePath = "C:\\ProgramData\\PlannerX"; 
    LPCSTR saveFile = "C:\\ProgramData\\PlannerX\\savefile.plx"; 

    cout << "Welcome to the Setup of PlannerX." << endl;
    cout << "Press [ENTER] to continue with the setup or press [ctrl] + [c] to abort this action." << endl;
    cin.get();
    system("cls");
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
    
}

void loadTasks(){
    //to-do
}

void saveTasks(){
    //to-do
}

void createTask(){
    //to-do
}

void solveTask(){
    //to-do
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
    }

    using namespace std;
    system("cls");

    int userChoice;
    bool inMainMenu = true;

    while (inMainMenu)
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

        cout << "[1] Create task" << endl;
        cout << "[2] Solve task" << endl;
        cout << ": ";
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            createTask();
            inMainMenu = false;
            break;

        case 2:
            solveTask();
            inMainMenu = false;
            break;
        
        default:
            break;
        }
    }
    



    return 0;
}
