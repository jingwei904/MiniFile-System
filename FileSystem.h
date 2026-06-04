#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "File.h"
#include "Folder.h"

class FileSystem{
private:
    Folder root;
    Folder* activeFolder;

public:
    FileSystem() : root("system67"){}

    //manage current folder
    //load file structure from file
    //manage menu operations
    //coordinate system operations:
        //create folder
        //creare file
        //display current folder
        //display full folder tree
        //search file
        //enter folder
        //go back to parent folder
        //delete file
        //delete folder
        //show current path
        //exit
};

#endif