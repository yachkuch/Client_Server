/// @author Якуш Н.А.
/// @version 1.0.0.
/// @date 17.11.2023
/// @details Классы с клиент серверными универсальными классами клиента и сервера
#pragma once
#include <stdint.h>
#include <type_traits>
#include <set>
#include <vector>
#include <map>
#include <functional>
#include <memory>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <thread>

#define local_host "127.0.0.1"

void test()
{
    std::cout << "Some sheet" << std::endl;
};

/// @brief Тип работы в виде клиента или серввера
enum class Server_Client_type : uint8_t
{
    client_socket = 0,
    server_socket = 1,
};

/// @brief состояние сокета
enum class SocketStatus : uint8_t
{
    connected = 0,
    err_socket_init = 1,
    err_socket_bind = 2,
    err_socket_connect = 3,
    disconnected = 4
};
/// @brief Вид применяемого протокола
enum class protocol_type : uint8_t
{
    TCP = 1,
    UDP = 2,
};
enum class socet_type : uint8_t
{
    potock_soclet = SOCK_STREAM,
    datagramm_socket = SOCK_DGRAM,
};

/// @brief Дефолтный хидер
struct Defaul_Heder
{

    uint32_t size;
    uint32_t type_message;

    Defaul_Heder() = default;
    Defaul_Heder(Defaul_Heder &head)
    {
        this->size = head.size;
        this->type_message = head.type_message;
    }
    Defaul_Heder(Defaul_Heder &&Head)
    {
        this->size = Head.size;
        this->type_message = Head.type_message;
    }
    ~Defaul_Heder() = default;
};
/// @brief Структура буфера привести указатель на буфер к умному указателю
struct Buffer
{
    char *buffer = nullptr;
    int buffer_size = 0;
    Buffer() = default;
    ~Buffer()
    {
        if (buffer != nullptr)
        {
            delete[] buffer;
        }
    }
};
/// @brief Структуры для проверки наличия параметра size у header
/// @tparam T
/// @tparam
template <class T, class = void>
struct Has_s : std::false_type
{
};

template <class T>
struct Has_s<T, std::void_t<decltype(std::declval<T>().size)>>
    : public std::true_type
{
};

/// @brief Класс сервера для приема и разбора сообщений
/// @tparam Header параметр заголовка сообщения ожидаемого в передаче
/// @author yachkuch@gmail.com
/// @brief  Универсальный класс сервера для приема и разбора сообщений
/// @tparam Header
/// @author yachkuch@gmail.com
template <typename Header = Defaul_Heder>
class Networker_base
{
protected:
    /// @brief Признак отвечающий за работу считывания
    bool Priznak_work = true;
    /// @brief Хедер сообщения
    Header heder;
    /*-----------------------------*/
    /// @brief Все сокеты
    std::set<SOCKET *> all_sockets;
    /// @brief Номер порта
    int port = 0;
    /// @brief Тип обработчика клиент или сервер
    uint8_t Client_Server_type = (uint8_t)Server_Client_type::client_socket;
    /// @brief Тип протокола
    uint8_t protocol_type = (uint8_t)protocol_type::TCP;
    /// @brief Вид сокета, потоковый или датаграммный
    uint8_t socket_type = (uint8_t)socet_type::potock_soclet;
    /// @brief Хранит в себе последний созданный сокет, чтобы серверу было удобно делать метод bind
    SOCKET *last_create_socket = nullptr;
    /// @todo разобраться с ридером
    // std::function<(char *)> default_reafer = nullptr;
    char *buff = nullptr;

    /// @brief Проверяет наличие размера у heder
    void has_perements()
    {
        Has_s<Header>;
    };

public:
    Networker_base()
    {
        has_perements();
        char buff2[1000];
        if (WSAStartup(0x0202, (WSADATA *)&buff2[0]))
        {
            // Ошибка!
            printf("Error WSAStartup %d\n", WSAGetLastError());
        }
        std::cout << "Server initialize" << std::endl;
    };
    Networker_base(const uint16_t port /*,uint8_t socket_type*/, uint8_t protocol_type) : port(port)
    {
        has_perements();
        char buff2[1000];
        if (WSAStartup(0x0202, (WSADATA *)&buff2[0]))
        {
            // Ошибка!
            printf("Error WSAStartup %d\n", WSAGetLastError());
        }
        std::cout << "Server initialize" << std::endl;
    };
    // @todo очистку и закрытие всех сокетов
    ~Networker_base()
    {
        printf("Close sockets %d\n", WSAGetLastError());
        for (auto a : all_sockets)
        {
            closesocket(*a);
        }
        WSACleanup();
    };

    void close_all_sock()
    {
        printf("Close sockets  %d\n", WSAGetLastError());
        for (auto a : all_sockets)
        {
            closesocket(*a);
        }
        WSACleanup();
    }

    std::function<void(char *buffer)> reader = nullptr;
    /// @brief Устанавливает признак работы
    /// @param Priznak признак работы
    void set_Priznak_work(bool Priznak)
    {
        this->Priznak_work = Priznak;
    };

    /// @brief Возвращает признак необходимости вычитывать сообщения
    /// @return
    bool get_Prizmak_work()
    {
        return this->Priznak_work;
    };
    /// @brief Добавляет новый сокет к обработке
    void add_socket()
    {
        SOCKET *new_socket = new SOCKET;
        if ((*new_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            std::cout << "Cant make socket" << std::endl;
            return;
        }
        all_sockets.insert(new_socket);
        last_create_socket = new_socket;
    }

    void listen_socket()
    {
        if (!listen(*last_create_socket, 0x100))
        {
            std::cout << "Cant listen socket" << std::endl;
            return;
        }
        std::cout << "listen connect" << std::endl;
        SOCKET client_socket;    // сокет для клиента
        sockaddr_in client_addr; // адрес клиента (заполняется системой)

        // функции accept необходимо передать размер структуры
        int client_addr_size = sizeof(client_addr);
        // цикл извлечения запросов на подключение из очереди
        while ((client_socket = accept(mysocket, (sockaddr *)&client_addr, &client_addr_size)))
        {
        }
    }

    void close_all_sockets()
    {
        auto iter = all_sockets.begin();
        while (iter != all_sockets.end())
        {
            close_socket(*iter);
        }
    }

    void close_socket(SOCKET *socket = nullptr)
    {
        if (socket == nullptr)
        {
            closesocket(*last_create_socket);
        }
        else
        {
            closesocket(*socket);
        }
        WSACleanup();
    }
    /// @brief Функция посылки
    /// @param buffer указатель на буффер
    /// @param soket сокет который должен осуществить посылку
    /// @param size  размер посылки
    void send_(std::unique_ptr<char> buffer, SOCKET *soket = nullptr, int size = 0)
    {
        if ((size != 0))
        {
            SOCKET *soc = nullptr;
            if ((soket == nullptr))
                soc = last_create_socket;
            if (buffer.get() == nullptr)
                std::cout << "Попытка послать пустой буфер" << std::endl;
            send(*soc, buffer.get(), size);
        }
        else
        {
            std::cout << "Автор сраный лентяй и не доделал чсасть где не передается параметр size" << std::endl;
        }
    }
};

/// @brief Класс сервера
/// @tparam Header
template <typename Header = Defaul_Heder>
class Serv_tcp_reader : public Networker_base<Header>
{
private:
    /* data */
public:
    Serv_tcp_reader(const uint16_t port, uint8_t socket_type, uint8_t protocol_type) : Networker_base<Header>(port, protocol_type)
    {
        std::cout << "Server has been construct" << std::endl;
    };
    ~Serv_tcp_reader(){};

    bool bind_socket()
    {
        if (last_create_socket == nullptr)
        {
            std::cout << "Не создано сокета на который происходит бинд" << std::endl;
        }
        sockaddr_in adress;
        adress.sin_family = AF_INET;
        adress.sin_port = htons(port);
        adress.sin_addr.S_un.S_addr = 0;
        if (bind(*last_create_socket, (sockaddr *)&adress, sizeof(adress)))
        {
            std::cout << "Сокет не биндится" << std::endl;
            return false;
        }
        if (listen(*last_create_socket, 0x100))
        {
            std::cout << "Oшибка прослушивания сокета" << std::endl;
            return false;
        }
        std::cout << "Listen connection" << std::endl;
        SOCKET client_socket;
        sockaddr_in client_addr;
        int client_addr_size = sizeof(client_addr);
        while ((client_socket = accept(*last_create_socket, (sockaddr *)&client_addr, &client_addr_size)))
        {
            HOSTENT *host;
            host = gethostbyaddr((char *)&client_addr.sin_addr.s_addr, 4, AF_INET);
            DWORD thID;
            std::thread(test);
            std::cout << "Create accept sheeeet" << std::endl;
            /// @todo нет функции передаваемой в поток
        }

        return true;
    }
    /// @brief Быстрый старт работы сервера достаточно передать все параметры в конструктор и вызвать данный метод
    /// @return true сервер инициализирован и ждет подключений false при инициализации ошибка
    bool fast_server_start()
    {
        this->add_socket();
        this->bind_socket();
        return true;
    }
};

/// @brief Класс клиента
/// @tparam Head
template <typename Head = Defaul_Heder>
class client : public Networker_base<Head>
{
private:
    /* data */
public:
    client(){};
    client(const uint16_t port, uint8_t sockete_type, uint8_t protocol_type) : Networker_base(port, protocol_type){};
    ~client(){};

    bool connect_()
    {
        sockaddr_in dest_addr;
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(port);
        HOSTENT *hst;

        if (inet_addr(local_host) != INADDR_NONE)
        {
            dest_addr.sin_addr.s_addr = inet_addr(local_host);
        }
        else
        {
            if (hst = gethostbyname(local_host))
            {
                ((unsigned long *)&dest_addr.sin_addr)[0] = ((unsigned long **)hst->h_addr_list)[0][0];
            }
            else
            {
                close_all_sockets();
                return false;
            }
        }
        if (last_create_socket == nullptr)
            add_socket();
        if (connect(*last_create_socket, (sockaddr *)&dest_addr, sizeof(dest_addr)))
        {
            std::cout << "Connect error" << std::endl;
            return false;
        }
        std::cout << "Connect_secsessful" << std::endl;
        return true;
    }
};
