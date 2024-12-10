mkdir build && cd build 
cmake -DCMAKE_BUILD_TYPE=Release .. -DUSE_NN=OFF -DHAVE_LIBREALSENSE=OFF
make -j$(nproc)