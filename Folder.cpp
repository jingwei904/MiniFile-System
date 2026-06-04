#include <iostream>
#include <string>
#include <vector>

#include "Folder.h"
#include "File.h"

using namespace std;

void Folder::renameFile(){
     string name("");
     string ext("");
     //display file names and index
     int index = 0;
     for(File fl : files){
          cout << endl;
          cout << index++ << ".\t";
          fl.getFile();
          cout << endl;
     }

     //let user pick the index
     cout << endl;
     cout << "Please select the file you wish to manage: ";
     cin >> index; cin.ignore(); --index;

     //access the file object
     //use setFileName() & setFileExt()
     cout << endl;
     cout << "Please rename your file: (original file name: " + files[index].getFile() + ")";
     cout << endl;
     getline(cin,name,'.'); getline(cin,ext);
     files[index].setFileName(name);
     files[index].setFileExt(ext);

     cout << endl;
     cout << "Congratulations, file successfully renamed to " + files[index].getFile();
     cout << endl;
}

void Folder::renameSubFolder(){
     string name("");

     //display file names and index
     int index = 0;
     for(Folder* f_ptr : subfolders){
          cout << endl;
          cout << index++ << ".\t";
          f_ptr->getFolderName();
          cout << endl;
     }
    
     //let user pick the index
     cout << endl;
     cout << "Please select the folder you wish to manage: ";
     cin >> index; cin.ignore(); --index;

     //access the file object
     cout << endl;
     cout << "Please rename your folder: (original file name: " + subfolders[index]->getFolderName() + ")";
     cout << endl;
     getline(cin,name);
     subfolders[index]->setFolderName(name);

     cout << endl;
     cout << "Congratulations, folder successfully renamed to " + subfolders[index]->getFolderName();
     cout << endl;
}

void Folder::folderTraversal(string prefix, bool isLast)const{
     for(int sub = 0; sub < subfolders.size(); sub++){
          isLast = (sub == subfolders.size() - 1 && files.empty())? true : false;
          cout << prefix << ((isLast)? "└── " : "├── ")
               << subfolders[sub]->name << endl;
          string newPrefix = prefix + ((isLast)? "    " : "│   ");
          subfolders[sub]->folderTraversal(newPrefix, isLast);
     }
     
     for(int f = 0; f < files.size(); f++){
          cout << prefix;
          cout << ((f != files.size() - 1)? "├── ": "└── ");
          cout << files[f].getFile() << endl;
     }
}

Folder* Folder::folderSearch(string folderName, int index){
     if(index >= 0 && index < subfolders.size()){
          if(folderName == subfolders[index]->getFolderName()){
               return subfolders[index];
          }else{
               Folder* folder = subfolders[index]->folderSearch(folderName);
               if(folder != nullptr){
                    return folder;
               }else{
                    return folderSearch(folderName, index + 1);
               }
          }
     }else{
          return nullptr;
     }
}

void Folder::deleteFile(string fileName, int index){
     if(index >= 0 && index < files.size()){
          if(fileName == files[index].getFile()){
               while(index >= 0 && index < (files.size() - 1)){
                    files[index] = files[++index];
               }
               files.pop_back();
          }else{
               deleteFile(fileName, index + 1);
          }
     }else{
          cout << endl;
          cout << "This file does not exist, please check again";
          cout << endl;
     }
}

void Folder::deleteFolder(string folderName, int index){
     if(index >= 0 && index < subfolders.size()){
          if(folderName == subfolders[index]->getFolderName()){
               delete subfolders[index];
               while(index >= 0 && index < (subfolders.size() - 1)){
                    subfolders[index] = subfolders[++index];
               }
               subfolders.pop_back();
          }else{
               deleteFolder(folderName, index + 1);
          }
     }else{
          cout << endl;
          cout << "This folder does not exist, please check again";
          cout << endl;
     }
}
