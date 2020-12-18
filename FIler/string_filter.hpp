//
//  strinf_filter.hpp
//  FIler
//
//  Created by Taeyong Seong on 2020/12/17.
//

#ifndef strinf_filter_hpp
#define strinf_filter_hpp


#include <string>
#include <regex>
#include <algorithm>
#include <cctype>
#include <iostream>

#include "global.cpp"

std::string filter(std::string s);
void extracts_url(std::string s);
#endif /* strinf_filter_hpp */
