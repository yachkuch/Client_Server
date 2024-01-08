#include <iostream>
#include <Protocol_communication.h>
#include <Serv_tcp_reader.h>
#include <chrono>
#include <thread>

struct Default_mes
{
	double a;
	int b;
};

int main(int, char **)
{
	std::cout << "Hello, from CLient!\n";

	client<> client(3466, 1, 1);
	auto resault = client.connect_();
	std::cout << "Client resault " << resault << std::endl;
	//Дефолтаная посылка сообщений
	Defaul_Heder heder;
	heder.type_message = 3;
	heder.size = sizeof(Defaul_Heder) + 66000;
	char *a = new char[sizeof(Defaul_Heder) + 66000];
	memset(a,1,65600);
	memset(a+65500,2,500);
	memcpy(a, &heder, sizeof(Defaul_Heder));
	for(int i =0;i<108;i++){
		std::cout<<a[i];
	}
	std::cout<<std::endl;
	for (int i = 0; i < 3; i++)
	{
		client.send_(a, sizeof(Defaul_Heder) + 66000);
		std::cout<<"send"<<std::endl;
		std::chrono::milliseconds timespan(11100); // or whatever
		std::this_thread::sleep_for(timespan);
	}
	std::this_thread::sleep_for(std::chrono::microseconds (100000));
	std::cout << "Finish"<<std::endl;
	system("Pause");
	return 0;
}
