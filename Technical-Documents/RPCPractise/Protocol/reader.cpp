//g++ -std=c++11 -I/usr/local/include -L/usr/local/lib -o reader reader.cpp lm.helloworld.pb.cc -lprotobuf -pthread
#include "lm.helloworld.pb.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void ListMsg(const lm::helloworld & msg) { 
  cout << msg.id() << endl; //打印出id值
  cout << msg.str() << endl;   //打印出str值
} 
  
 int main(int argc, char* argv[]) { 
 
  lm::helloworld msg1; 
  
  { 
    fstream input("./log", ios::in | ios::binary); //从./log文件中建立输入流
    if (!msg1.ParseFromIstream(&input)) {   //解析输入流
      cerr << "Failed to parse address book." << endl; 
      return -1; 
    } 
  } 
  
  ListMsg(msg1); 
 }
