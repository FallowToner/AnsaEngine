cd /Ansa
mkdir build
cd build
cmake .. || exit 1
cmake --build . || exit 1
ctest . || exit 1
cd ..
tar -zcvf bin.tar.gz ./build/bin 
