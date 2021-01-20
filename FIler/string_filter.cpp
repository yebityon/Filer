//
//  strinf_filter.cpp
//  FIler
//
//  Created by Taeyong Seong on 2020/12/17.
//

#include "constant.hpp"

extern std::vector<std::string> urls;

std::regex pt{rpst};
std::smatch match;

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
void extract_urls(const std::string s){
    auto ts = s;
    while (std::regex_search(ts, match, pt)) {
    //    std::cout << match[0].str() << std::endl;
        std::string  ss(match[0].str());
        if(ss.find(base_replace_string) != std::string::npos)
            urls.emplace_back(match[0].str());
        ts = match.suffix();
    }
}
std::string filter(std::string s){
    
    int offset = (int)base_replace_string.size() - (int)base_remove_string.size();

    std::string  ls = s;
    std::transform(ls.begin(), ls.end(), ls.begin(),[](unsigned char c){
        return std::tolower(c);
    });
    while(ls.find(base_remove_string) != std::string::npos){
        int id = (int)ls.find(base_remove_string);
        auto substr = s.substr(id,base_remove_string.size());
        ls.replace(id, base_remove_string.size(), base_replace_string);
        s.replace(id + offset, substr.size(), create_replaced_string(substr));
    }
    extract_urls(ls);
    return s;
}


