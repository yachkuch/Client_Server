#include <iostream>
#include <thread>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <vector>

#include"Serv_tcp_reader.h"
#include"Protocol_communication.h"
#include<Protocol_pak.h>

void workerFunc() 
{
	Serv_tcp_reader<> server(3466, 1, 1);
	std::cout << "Start bind socket" << std::endl;
	std::thread th2;
	std::cout<<std::endl;
	auto val = server.fast_server_start();
} 

void workerFunc2(){
	client<> client(3466,1,1);
	auto resault = client.connect_();
	std::cout<<"Client resault "<<resault<<std::endl;
}
 
int main(int argc, char* argv[]) 
{
setlocale(LC_ALL, "Russian");
std::cout<<"Hello"<<std::endl;
std::thread thread(workerFunc);
thread.detach();
std::cout<< "Make client"<<std::endl;
std::thread t2(workerFunc2);
t2.detach();
std::cout << "Finish";
system("Pause");
 return 0; 
}
