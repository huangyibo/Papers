//g++ -std=c++11 -I/usr/local/include -L/usr/local/lib -o writer writer.cpp lm.helloworld.pb.cc -lprotobuf -pthread
#include "lm.helloworld.pb.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void){ 
   
  lm::helloworld msg1;   //创建一个对象，类名为包名::消息名
  msg1.set_id(101);  //设置消息中的id值 
  msg1.set_str("Hello World!");  //设置消息中的string值   
     
  // Write the new address book back to disk. 
  fstream output("./log", ios::out | ios::trunc | ios::binary); //将消息写出到.log文件中
         
  if (!msg1.SerializeToOstream(&output)) {    //序列化写出
      cerr << "Failed to write msg." << endl; //如果写出错误，则输出错误提示
      return -1; 
  }         
  return 0;
}
