## **使用到的第三方开发Library**

* Boost https://www.boost.org/
* Dlib http://dlib.net/   安装Dlib之前首先应该编译Boost
* TensorFlow  https://www.tensorflow.org/
* igraph http://igraph.org/
* libpqxx https://github.com/jtv/libpqxx
* json-c https://github.com/json-c/json-c


## **使用的技术**

* RDMA Remote Direct Memory Access  远程内存直接访问
* Graph Theory and Graph Database
* storage techniques
    * NVMe SSD
* Linux System Programming
    * system call
    * glibc
    * C Compile
    * GNU Makefile https://seisman.github.io/how-to-write-makefile/overview.html
* 库的编译与安装
    * pkg-config 使用 https://people.freedesktop.org/~dbn/pkg-config-guide.html ，尤其要学会写.pc文件，并添加到环境变量中
    * 编译动态与静态链接库，通过写.pc文件，使得pkg-config可用 
```shell
gcc -fPIC -shared -o libxxx.so.1.0.0 xxx.c 将共享库编译为标准格式libxxx.so.1.0.0   
ln -s libxxx.so.1.0.0 libxxx.so    建立符号链接，将其指向最新版本的共享库
```
* RPC （Romote Procedure Calls） 远程过程调用
    * 安装`sudo apt-get install rpcbind`，用其提供portmap服务
    * RPC programming
* 并行程序设计（Parallel Programming）
    * pthread多核并行程序设计
    * GPU数据并行程序设计
* Machine Learning 机器学习
    * 监督学习
    * 非监督学习
