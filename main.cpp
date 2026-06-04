#include <iostream>
#include <string>

#include "Folder.h"

using namespace std;

int main(){
    //placeholder
    Folder* activeFolder;
    Folder folder("system67");
    activeFolder = &folder;
    activeFolder->addSubfolder("Courses");
    activeFolder->addSubfolder("Images");
    activeFolder->addSubfolder("Projects");
    activeFolder->addFile("report","txt");

    activeFolder = folder.folderSearch("Courses");
    activeFolder->addSubfolder("OOP");
    activeFolder->addSubfolder("Database");
    
    activeFolder = folder.folderSearch("OOP");
    activeFolder->addFile("assignment","docx");
    activeFolder->addFile("notes","pdf");

    activeFolder = folder.folderSearch("Database");
    activeFolder->addFile("lab","sql");
    
    activeFolder = folder.folderSearch("Images");
    activeFolder->addFile("diagram","png");
    
    activeFolder = folder.folderSearch("Projects");
    activeFolder->addSubfolder("FYP");

    activeFolder = folder.folderSearch("FYP");
    activeFolder->addFile("proposal","docx");

    activeFolder = &folder;

    cout << endl << endl;
    cout << activeFolder->getFolderName() << endl;
    activeFolder->folderTraversal();
    //end of placeholder
    
    return 0;
}