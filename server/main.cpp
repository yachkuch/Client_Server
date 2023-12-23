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

struct Default_mes
{
	double a;
	int b;
};

void workerFunc()
{
	Serv_tcp_reader<> server(3466, 1, 1);
	std::cout << "Start bind socket" << std::endl;
	// std::thread th2();
	std::cout << std::endl;
	auto val = server.fast_server_start();
}
//! @todo TODO: dsjfg
void workerFunc2()
{
	client<> client(3466, 1, 1);
	auto resault = client.connect_();
	std::cout << "Client resault " << resault << std::endl;
	Defaul_Heder heder;
	heder.type_message = 2;
	heder.size = sizeof(Defaul_Heder);
	Default_mes mes;
	mes.a = 1;
	mes.b = 2;
	char *a = new char[sizeof(Defaul_Heder) + sizeof(Default_mes)];
	client.send_(a, sizeof(Defaul_Heder) + sizeof(Default_mes));
	// system("Pause");
}

int main(int argc, char *argv[])
{
	Buffer a;
	std::unique_ptr<char []> value(new char [10]);
	memset(value.get(),7,10);
	a.set_buffer(std::move(value));
	setlocale(LC_ALL, "Russian");
	Serv_tcp_reader<> server(3466, 1, 1);
	std::cout << "Start bind socket" << std::endl;
    int ass = 0;
	std::cout << std::endl;
	auto val = server.fast_server_start();
    std::cout<<val;
	system("Pause");
	return 0 ;
}
