//
//  strinf_filter.cpp
//  FIler
//
//  Created by Taeyong Seong on 2020/12/17.
//

#include "constant.hpp"
static const std::string remove_string = "yebityon";
static const std::string replace_string = "remutyan!";
const std::string rpst = "/^(?:([A-Za-z]+):)?(\\/{0,3})([0-9.\\-A-Za-z]+)(?::(\\d+))?(?:\\/([^?#]*))?(?:\\?([^#]*))?(?:#(.*))?$/";
std::regex pt{rpst};

extern std::vector<std::string>urls;
void extract_urls(const std::string s){
    std::sregex_iterator end, ite{s.begin(), s.end(), pt};
    for (; ite != end ; ++ite) {
        if(std::find(ite->begin(),ite->end(),replace_string) != ite->end())
            urls.push_back(ite->str());
    }
    urls.emplace_back(s);
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


