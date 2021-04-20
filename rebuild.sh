rm -rf ./build
mkdir build
cd build
cmake -G "Xcode" -DPROJECT_ARCH="x86_64" ..
