#！/bin/bash
cd ../3rdparty/libsodium/

./configure

make && make check

sudo make install