# OpenVINS Without ROS and Boost
Based on OpenVINS

More detail visit follow website

* Github project page - https://github.com/rpng/open_vins
* Documentation - https://docs.openvins.com/
* Getting started guide - https://docs.openvins.com/getting-started.html
* Publication reference - http://udel.edu/~pgeneva/downloads/papers/c10.pdf

## Compile
```bash
sudo apt install libopencv-dev
sudo apt install libceres-dev
sudo apt install libeigen3-dev
mkdir build
cd build
cmake ..
make -j8
```

## TODO
1. Separate visual frontend from vio manager
2. Add config singleton
2. Add vio app
