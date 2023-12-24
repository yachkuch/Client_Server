#pragma once
#include <stdint.h>
#include <vector>

/// Протокол передачи сообщений переменной длинны

/// @brief Структура заголовка сообщения
struct Header
{
    uint8_t uniq_type;
    uint8_t size;
    uint8_t version_protocol;
};
/// @brief Контрольное сообщение
struct Control_message
{
    uint32_t id_abonent;
};
/// @brief Титл содержащий дополнительную техн информацию
struct Title
{
    uint32_t sender_id;
    uint32_t sender_resiver;
};

struct specificatoin
{
    std::vector<char> buffer;
};

/// @brief Абстрактный тип структур полей сообщения
struct abstract_type
{
};

struct abstract_message_type
{
public:
    /// @brief Функция подчитывающая итоговый размер сообщения по передаваемой в него спецификации
    /// @param specification
    /// @return
    virtual int get_size_mes(std::vector<char> specification) = 0;

    /// @brief Возвращеает набор байт спецификации
    /// @param full_spec Вектор в котором находятся поля подлежащие отправке
    /// @return Набор спецификации байт
    static std::vector<char> set_full_specification(std::vector<bool> full_spec)
    {
        int size = full_spec.size();
        int count = 0;
        if (size < 8)
        {
            for (const auto &el : full_spec)
            {
                count++;
            }
        } else {

        }
    }

private:
    /// BUG: Биты должны расставляться в другой последовательности
    /// @brief Возвращает байт с полями для спецификации
    /// @param elem массив с позициями в которых должны находиться элементы
    /// @param need_spend байт необходимости продолжения спецификации
    /// @return байт спецификации
    static char set_spec(bool elem[8])
    {
        char x = 0;
        for (int i = 0; i < 7; i++)
        {
            if (elem[i] == true)
                x |= (1 << i);
            else
                x &= ~(1 << i);
        }
        return x;
    }
};

/// @brief Посылаемое сообщение первой категории
struct type1 : public abstract_message_type
{

    int get_size_mes(std::vector<char> specification) override final
    {
        int counter = 0;
        int result_size = 0;
        for (const auto &byte : specification)
        {
        }
        return result_size;
    }

    struct Pol1_1 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol1;

    struct Pol1_2 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol2;

    struct Pol1_3 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol3;

    struct Pol1_4 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol4;

    struct Pol1_5 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol5;

    struct Pol1_6 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol6;

    struct Pol1_7 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol7;

    struct Pol_prodolg_1
    {
        char byte;
    };

    struct Pol1_8 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol8;

    struct Pol1_9 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol9;

    struct Pol1_10 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol10;

    struct Pol1_11 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol11;

    struct Pol1_12 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol12;

    struct Pol1_13 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol13;

    struct Pol1_14 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol14;

    struct Pol_prodolg_2
    {
        char byte;
    };
};

/// @brief Посылаемое сообщение второй категории
struct type2 : public abstract_message_type
{

    int get_size_mes(std::vector<char> specification) override final
    {
        int counter = 0;
        int result_size = 0;
        for (const auto &byte : specification)
        {
        }
        return result_size;
    }

    struct Pol1_1 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol1;

    struct Pol2_2 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol2;

    struct Pol2_3 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol3;

    struct Pol2_4 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol4;

    struct Pol2_5 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol5;

    struct Pol2_6 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol6;

    struct Pol2_7 : abstract_type
    {
        uint8_t A1;
        uint8_t A2;
    } pol7;
};