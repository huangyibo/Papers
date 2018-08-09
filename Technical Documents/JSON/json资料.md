### **json-c安装与使用**

#### **安装步骤**

```shell
sudo apt install git
sudo apt install autoconf automake libtool
sudo apt install valgrind # optional
...下载好json-c的压缩包，并解压，进入到根目录下
./configure 
make -j 4
sudo make check -j 4
sudo make install  #完成安装
pkg-config --cflags --libs json-c   #会给出编译json-c程序时需要的-I和-L参数的路径，注意，需要将-L参数的路径添加到/etc/ld.so.conf
sudo ldconfig
```
完成上述步骤之后，打开Eclipse CDT，将-I和-L指定的路径分别添加到Include Paths和Library Paths下，写好代码，就能直接编译。


#### **参考资料**

1. JSON官网及其对应的各种语言JSON库 https://www.json.org/
2. JSON-C 官当文档 https://github.com/json-c/json-c
