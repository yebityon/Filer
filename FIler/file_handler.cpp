//
//  replace_strings.cpp
//  FIler
//
//  Created by Taeyong Seong on 2020/12/17.
//

#include "constant.hpp"
#include "string_filter.hpp"

int write_file(const std::string fileName,const std::vector<std::string>&buffers){
    std::ofstream writing_file;
    writing_file.open(fileName);
    std::cout << "writing... " << fileName << std::endl;
    for(const auto& s : buffers){
        writing_file << s << std::endl;
    }
    writing_file.close();
    return 0;
}

int read_file(const std::string fileName){
    std::ifstream reading_file;
    std::vector<std::string>str;
    reading_file.open(fileName,std::ios::in);
    std::cout << "reading file..."  << fileName << std::endl;
    while(!reading_file.eof()){
        std::string reading_line_buffer;
        std::getline(reading_file, reading_line_buffer);
        str.emplace_back(filter(reading_line_buffer));
    }
    reading_file.close();
    std::cout << "finished reading... " << fileName << std::endl;
    write_file(fileName,str);
    return 0;
}

