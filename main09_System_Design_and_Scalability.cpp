#include "stdafx.h" // for windows version
#include "cppcoding.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>
using namespace std;
#include <windows.h>
// C++ Program to get the current working directory
#include <iostream>   
#include <direct.h>  

int main09(){
   
    fstream newfile;
    newfile.open("data.txt", ios::in);
   

    if (newfile.is_open()) {
        string str;
        while (getline(newfile, str)) {
            cout << str << "\n";
        }
        newfile.close(); //close the file object.

        reverse(str.begin(), str.end());

        newfile.open("newdata.txt", ios::out);
        if (newfile.is_open())
            newfile << str;
        newfile.close();

    }
    
    return 0;
}
