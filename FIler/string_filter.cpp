//
//  strinf_filter.cpp
//  FIler
//
//  Created by Taeyong Seong on 2020/12/17.
//

#include "constant.hpp"
static const std::string remove_string = "peertube";
static const std::string replace_string = "Aleftube";
extern std::vector<std::string> urls;
const std::string rpst = "(https?:\\/\\/(?:www\\.|(?!www))[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\\.[^\\s]{2,}|www\\.[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\\.[^\\s]{2,}|https?:\\/\\/(?:www\\.|(?!www))[a-zA-Z0-9]+\\.[^\\s]{2,}|www\\.[a-zA-Z0-9]+\\.[^\\s]{2,})";
std::regex pt{rpst};
std::smatch match;
void extract_urls(const std::string s){
    auto ts = s;
    while (std::regex_search(ts, match, pt)) {
//        std::cout << match[0].str() << std::endl;
        std::string  ss(match[0].str());
        if(ss.find(replace_string) != std::string::npos)
            urls.emplace_back(match[0].str());
        ts = match.suffix();
    }
}
std::string filter(std::string s){
    extract_urls(s);
    std::string  ls = s;
    std::transform(ls.begin(), ls.end(), ls.begin(),[](unsigned char c){
        return std::tolower(c);
    });
    while(ls.find(remove_string) != std::string::npos){
        int id = (int)ls.find(remove_string);
        ls.replace(id, remove_string.size(), replace_string);
        s.replace(id, remove_string.size(), replace_string);
    }
    return s;
}


