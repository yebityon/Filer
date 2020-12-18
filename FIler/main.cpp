//
//  main.cpp
//  FIler
//
//  Created by Taeyong Seong on 2020/12/17.


#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "file_handler.hpp"
#include "global.cpp"

const std::vector<std::string>valid_extension_type = {".txt",".md",".dat",".csv",".cpp"};
int main(int argc, const char * argv[]) {
    if(argc != 3){
        std::cout << "USAGE : [path where you travel]" << std::endl;
        exit(0);
    }
    namespace fs = std::filesystem;
    const std::string ouput_csv_filename = argv[2];
    for(const fs::directory_entry &i: fs::recursive_directory_iterator(argv[1])){
        if(fs::is_directory(i)) continue;
        if(fs::is_regular_file(i)){
            const std::string extension_type = i.path().extension();
            if(std::find(valid_extension_type.begin(), valid_extension_type.end(), extension_type) != valid_extension_type.end()){
                read_file(i.path());
            } else {
                std::cout << "skipped... " << i.path() << std::endl;
            }
            
        }
    }
}
