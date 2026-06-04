notes:

[ ] Load initial structure from fileSystem.txt

[ ] Create folder
    [ ] Empty folder name exception case //try{}catch{}
    [ ] Duplicate name exception case    //try{}catch{}
    [/] Dynamic allocation of folder

[ ] Create file
    [ ] User's input
    [ ] Empty folder name exception case //try{}catch{}
    [ ] Duplicate name exception case    //try{}catch{}
    [/] Dynamic allocation of file

[/] Display current folder --// void Folder::folderTraverse();
    - activeFolder->folderTraverse();
    [/] Current folder name
    [/] All files and subfolders inside folder

[/] Display full folder tree --// void Folder::folderTraverse();
    - activeFolder->folderTraverse();
    [/] Recursion implementation

[ ] Search file --// void Folder::folderSearch(fileName);
    [ ] User's input
    [/] Recursion implementation

[ ] Enter folder --// void Folder::folderSearch(fileName);
    [ ] User's input
    [ ] Exception handling              //try{}catch{}
    [/] Enter folder

[ ] Go back to parent folder --// Folder* Folder::getParent();
    [/] General cases
    [ ] Root case exception handling     //try{}catch{}

[ ] Delete file
    [ ] User's input
    [/] Finds and delete file --// void Folder::deleteFile(fileName);
    [ ] Nonexistent file exception handling //try{}catch{}

[ ] Delete folder
    [ ] User's input
    [/] Finds and delete file --// void Folder::deleteFolder(folderName);
    [ ] Nonexistent file exception handling //try{}catch{}

[ ] Show current path
    [ ] display current path

other notes:
