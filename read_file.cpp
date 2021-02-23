#include <iostream>
#include "WordList.hpp"
#include <fstream>
#include <string>
#include <cctype>

using std::ifstream; using std::string; using std::cout; using std::endl;


int main(int argc, char *argv[]){
    WordList obj;
   
    if (argc < 1) {
          cout << "No file name entered. Exiting...";
            return -1;
        }
    ifstream read_file(argv[1]);
    
    if(read_file.is_open()){
        cout << "File is now open!\n";
        cout << "file name: " << argv[1] << endl;
    }
    else{
        cout << "Failed to open the file...existing...\n";
        return -1;
    }
    string line;
    string abc = "";
    while(getline(read_file, line)){
        for(int i = 0; i< line.size(); i++){
            if(isalpha(line[i])){
                abc = abc + line[i];
                   if(!isalpha(line[i + 1]) && line[i + 1] != '-' && line[i + 1] != '\''){
                                obj.addWord(abc);
                                abc = "";
                }
                
            }
            else if(line[i] == '-' ||  line[i] == '\''){
                if(isalpha(line[i + 1]) && abc.size() != 0)
                    abc = abc + line[i];
                else if(abc.size() != 0){
                    obj.addWord(abc);
                    abc = "";
                }
            }
            else if(isdigit(line[i])){
                abc = abc + line[i];
                if(!isdigit(line[i + 1])){
                    obj.addWord(abc);
                    abc = "";
                }
                    
            }
        }
    }
    
    cout << endl;
    obj.sort();
    obj.print();
    return 0;
}



