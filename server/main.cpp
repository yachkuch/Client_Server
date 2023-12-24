#pragma once
#include <iostream>
#include <thread>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <vector>

// #include<unistd.h>

#include<Serv_tcp_reader.h>
#include "Protocol_communication.h"
#include <Protocol_pak.h>

class My_pril{
	public:
	My_pril(int a){
		std::function<void(Buffer *buf)> default_mes_handler = [](Buffer *buf){
		std::cout<<"Hello"<<std::endl;
	};
	Serv_tcp_reader<> server(3466, 1, 1);
	//server.set_default_mes_handler(default_mes_handler);
	std::cout << "Start bind socket" << std::endl;
    int ass = 0;
	std::cout << std::endl;
	auto val = server.fast_server_start();
    std::cout<<val;
	};

	void b(){
		std::cout<<"something"<<std::endl;
	}
};

int main(int argc, char *argv[])
{
	std::vector<bool> a = {0,0,0,1,0,0,0};
	setlocale(LC_ALL, "Russian");
	My_pril pril(3);
	std::cout<<"Sheet"<<std::endl;
	system("Pause");
	return 0 ;
}
