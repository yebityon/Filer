#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    if(argc != 3){
        cout << "USAGE : [target dir] [compared dir]" << endl;
        exit(0);
    }
    namespace fs = std::filesystem;
    vector<fs::path>l,r;
    const std::string l_name = argv[1];
    const std::string r_name = argv[2];
    for(const fs::directory_entry &i : fs::recursive_directory_iterator(l_name)){
        if(fs::is_directory(i))continue;
        if(fs::is_regular_file(i)){
            const std::string path_name = i.path();
            l.emplace_back(path_name);
        }
    }
    for(const fs::directory_entry &i : fs::recursive_directory_iterator(r_name)){
        if(fs::is_directory(i))continue;
        if(fs::is_regular_file(i)){
            const std::string path_name = i.path();
            r.emplace_back(path_name);
        }
    }
    for(const auto& i : r){
        auto rstr = i.string();
        auto rstr_sub = r_str.substr(rstr.find("//"));
        for(const auto& j : l) {
            auto lstr = j.string();
            auto l
        }
    }
    char *s = (char *)malloc(sizeof(char) * 1000);
    char *diff = "diff ";
    strcat(s,diff);
    strcat(s,argv[1]); strcat(s," "); strcat(s,argv[2]);
    strcat(s,">> yebityon.out");
    system(s);
}
