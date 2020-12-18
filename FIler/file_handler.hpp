//
//  replace_strings.hpp
//  FIler
//
//  Created by Taeyong Seong on 2020/12/17.
//

#ifndef replace_strings_hpp
#define replace_strings_hpp

#include <stdio.h>
#include <string>
#include "global.cpp"

int read_file(const std::string fileName);
int write_file(const std::string fileName,const std::vector<std::string>&buffers);
#endif /* replace_strings_hpp */

