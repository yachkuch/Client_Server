#pragma once
#include <vector>
#include<memory>

#include"Protocol_communication.h"

class Protocol_handler
{
private:
    Title title;
    /// @brief Вектор в котором содержатся сообщения 
    std::vector<abstract_type> data;
    /// @brief Хидер посылаемого сообщения 
    Header header;

    /// Методы по работе с ссобщением 

    
public:
    /// @brief Устанавливает титл с информацией о посылающем и принимающем сообщение
    /// @param tl Титл для установки
    void set_title(Title tl);
    /// @brief Формирует сообщение для посылки
    void Make_message_for_send();
    /// @brief Очищает весь хендлер для подготовки к посылке нового сообщения 
    void clear_handler();
    /// @brief Устанавливает тип посылаемого или принимаемого сообщения
    /// @param type Уникальный номер типа 
    void set_type_mes(int type);
    /// @brief  Устанавливает версию протокола
    /// @param version_version  номер версии протокола
    void set_protcol_version(int version_version);
    /// @brief Устанавливает размер сообщения
    /// @param size размер
    void set_size_message(int size);

    /// @brief Возвращает указаетль на набор посылаемых байт
    /// @return 
    std::unique_ptr<char[]> get_send_buffer();
};


class Pack_protocol{
    

};