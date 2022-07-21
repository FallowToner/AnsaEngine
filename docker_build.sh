cd /Ansa
mkdir build || exit 1
cd build
cmake .. || exit 1
cmake --build . || exit 1
ctest . || exit 1
cd ..
tar -zcvf bin.tar.gz ./build/bin || exit 1 
