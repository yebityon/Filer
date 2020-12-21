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
#include <cassert>
namespace fs = std::filesystem;
std::string remove_root_dir(std::string s){
    return s.substr(s.find("/"));
}
void ouput_diff(const fs::path origin, const fs::path target,const std::string dif_ouptput_dir){
    const std::string fileName = origin.filename();
    std::string output_dir = dif_ouptput_dir + remove_root_dir(target);
    std::string s = "diff " + origin.string() + " " + target.string() + " >> " + output_dir + "_diff.txt";
    system(s.c_str());
}
std::vector<std::string>urls;
const std::vector<std::string>valid_extension_type = {".txt",".md",".dat",".csv",".cpp",".html",".yml",".json","xml","mht","xhtml","asc",".css",".xsl",".js",".pl",".bat",".ts",".scss",".conf",".xlf",".sh",".sql",".mustache",".pug","",".buster"};

int main(int argc, const char * argv[]) {
    if(argc != 4){
        std::cout << "USAGE : [path/to/origin_dir] [path/to/target_dir] [path/to/diff_ouput_dir]" << std::endl;
        exit(0);
    }
    const std::string original_dir = argv[1];
    const std::string target_dir = argv[2];
    const std::string ouput_dir = argv[3];
    std::cout << "original_dir: " << original_dir << std::endl;
    std::vector<fs::path>original,target;
    for(const fs::directory_entry &i : fs::recursive_directory_iterator(original_dir)){
        if(fs::is_directory(i)){
            std::string s = "mkdir " + ouput_dir + "/" + remove_root_dir(i.path().string());
            system(s.c_str());
            continue;
        }
        if(fs::is_regular_file(i)){
            const std::string path_name = i.path();
            original.emplace_back(path_name);
        }
    }
    for(const fs::directory_entry &i : fs::recursive_directory_iterator(target_dir)){
        if(fs::is_directory(i))continue;
        if(fs::is_regular_file(i)){
            const std::string path_name = i.path();
            target.emplace_back(path_name);
        }
    }
    for(auto& origin_file_path : original){
        auto file_path = remove_root_dir(origin_file_path.string());
        bool find_pair = false;
        for(auto& target_file_path : target){
            auto s = remove_root_dir(target_file_path.string());
            if(file_path == s){
                find_pair = true;
                ouput_diff(origin_file_path,target_file_path,ouput_dir);
                break;
            }
        }
        if(not find_pair){
            std::cout << file_path << std::endl;
        }
        assert(find_pair);
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
}


