//
//  constant.hpp
//  FIler
//
//  Created by Taeyong Seong on 2020/12/18.
//

#ifndef constant_hpp
#define constant_hpp

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <filesystem>
#include <algorithm>

const std::vector<std::string>valid_extension_type = {".txt",".md",".dat",".csv",".cpp",".html",".yml",".json","xml","mht","xhtml","asc",".css",".xsl",".js",".pl",".bat",".ts",".scss",".conf",".xlf",".sh",".sql",".mustache",".pug","",".buster",".service",".example",".yaml",".webmanifest",".rb",".haml",".rake",".atom",".map",".tpl"};

static const std::string base_remove_string =  "mastodon";
static const std::string base_replace_string = "aleftime";

const std::string rpst = "(https?:\\/\\/(?:www\\.|(?!www))[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\\.[^\\s]{2,}|www\\.[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\\.[^\\s]{2,}|https?:\\/\\/(?:www\\.|(?!www))[a-zA-Z0-9]+\\.[^\\s]{2,}|www\\.[a-zA-Z0-9]+\\.[^\\s]{2,})";


#endif /* constant_hpp */
