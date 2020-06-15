#！/bin/bash
cd ../3rdparty/protobuf/

mkdir build 

cd build

cmake    -DCMAKE_POSITION_INDEPENDENT_CODE=ON   -DCMAKE_BUILD_TYPE=Release   -Dprotobuf_BUILD_TESTS=OFF   ../cmake

make -j4

sudo make install