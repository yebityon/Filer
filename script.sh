rm -rf diff_dir
mkdir diff_dir
rm output.csv
rm -rf target
mkdir target
cp -r  origin/ target/
xcodebuild -project Filer.xcodeproj -alltargets -configuration Release
./build/Release/FIler target output.csv
rm diff_script
rm rename_script
g++-8 -std=c++17 -lstdc++fs -o diff_script diff_script.cpp
g++-8 -std=c++17 -lstdc++fs -o rename_script rename_script.cpp
./diff_script origin target diff_dir
./rename_script target
./rename_script target
