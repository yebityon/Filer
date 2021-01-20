//
//  main.cpp
//  file_differ
//
//  Created by Taeyong Seong on 2020/12/19.
//
#include <filesystem>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

namespace fs = std::filesystem;
std::string remove_root_dir(std::string s){
    return s.substr(s.find("/"));
}
std::vector<fs::path>vec;
static const std::string base_remove_string =  "mastodon";
static const std::string base_replace_string = "aleftime";
std::string create_replaced_string(const std::string& base){
    auto res = base_replace_string;
    for(int i = 0; i < base.size(); ++i){
        if( 'a' <= base[i] && base[i] <= 'z'){
            
        } else {
            res[i] = toupper(res[i]);
        }
    }
    return res;
}
=======
static const std::string remove_string =  "peertube";
static const std::string replace_string = "aleftube";
>>>>>>> c36639d87c2a848df1141104ad02b1e78e0dd67f

std::string filter(std::string s){
    std::string  ls = s;
    std::transform(ls.begin(), ls.end(), ls.begin(),[](unsigned char c){
        return std::tolower(c);
    });
<<<<<<< HEAD
    while(ls.find(base_remove_string) != std::string::npos){
        int id = (int)ls.find(base_remove_string);
        auto substr = s.substr(id,base_remove_string.size());
        ls.replace(id, base_remove_string.size(), base_replace_string);
        s.replace(id, substr.size(), create_replaced_string(substr));
    }
    return s;
}
void rename_folder(const fs::path origin){
    fs::path target = fs::path(filter(origin.string()));
    auto ls = origin.string();
    std::transform(ls.begin(), ls.end(), ls.begin(),[](unsigned char c){
        return std::tolower(c);
    });
    if(ls.find(base_remove_string) == std::string::npos) return;
=======
    while(ls.find(remove_string) != std::string::npos){
        int id = (int)ls.find(remove_string);
        ls.replace(id, remove_string.size(), replace_string);
        s.replace(id, remove_string.size(), replace_string);
    }
    return s;
}

void rename_folder(const fs::path origin){
    fs::path target = fs::path(filter(origin.string()));
    if(origin.string().find(remove_string) == std::string::npos) return;
>>>>>>> c36639d87c2a848df1141104ad02b1e78e0dd67f
    vec.emplace_back(origin);
    return;
}
std::vector<std::string>urls;
const std::vector<std::string>valid_extension_type = {".txt",".md",".dat",".csv",".cpp",".html",".yml",".json","xml","mht","xhtml","asc",".css",".xsl",".js",".pl",".bat",".ts",".scss",".conf",".xlf",".sh",".sql",".mustache",".pug","",".buster"};

int main(int argc, const char * argv[]) {
    if(argc != 2){
        std::cout << "USAGE : [path/to/rename_dir]" << std::endl;
        exit(0);
    }
    const std::string original_dir = argv[1];
    std::vector<fs::path>original,target;
    for(const fs::directory_entry &i : fs::recursive_directory_iterator(original_dir)){
        if(fs::is_directory(i)){
            //std::cout << i.path().string() << std::endl;
            rename_folder(i.path());
        }
    }
    std::sort(vec.begin(),vec.end());
    for(const auto& origin : vec){
        std::string s = "mv " + origin.string() + " " + filter(origin.string());
        system(s.c_str());
    }
    vec.clear();
    for(const fs::directory_entry &i : fs::recursive_directory_iterator(original_dir)){
        rename_folder(i.path());
    }
    std::sort(vec.begin(),vec.end());
    for(const auto& origin : vec){
        std::string s = "mv " + origin.string() + " " + filter(origin.string());
        system(s.c_str());
    }
}
//    for(const fs::directory_entry &i: fs::recursive_directory_iterator(argv[1])){
//        if(fs::is_directory(i)) continue;
//        //if(fs::is_regular_file(i)){
//        const std::string extension_type = i.path().extension();
//        if(std::find(valid_extension_type.begin(), valid_extension_type.end(), extension_type) != valid_extension_type.end()){
////            read_file(i.path());
//            //} else {
//            //   std::cout << "skipped... " << i.path() << std::endl;
//            //}
//        }
//    }
//  write_file(ouput_csv_filename,urls);

