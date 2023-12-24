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
    /// @brief Возвращеает набор байт спецификации и размер сообщения
    /// @param full_spec Вектор в котором находятся поля подлежащие отправке
    /// @return Набор спецификации байт
    std::pair<std::vector<char>,int> set_full_specification(std::vector<bool> full_spec)
    {
        int size = full_spec.size();
        std::vector<char> return_val;
        int count = 0;
        int size_mes = 0;
        bool spec[] = {0, 0, 0, 0, 0, 0, 0, 0};
        if (size < 8)
        {
            for (const auto &el : full_spec)
            {
                spec[count] = el;
                size_mes+=get_size_mes(count+1);
                count++;
            }
            return_val.push_back(abstract_message_type::set_spec(spec));
        }
        else
        {
            int number_byte = 1;
            for (const auto &el : full_spec)
            {
                spec[count] = el;
                size_mes+=get_size_mes(count,number_byte);
                if (count % 6 == 0)
                {
                    return_val.push_back(abstract_message_type::set_spec(spec));
                    memset(spec, 0, 8);
                    count = 0;
                    number_byte++;
                }
                count++;
            }
            return_val.push_back(abstract_message_type::set_spec(spec));
        }
        return std::make_pair(return_val,size_mes) ;
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

    /// @brief Функция подчитывающая итоговый размер сообщения по передаваемой в него спецификации
    /// @param specification
    /// @return
     virtual int get_size_mes(int number_bite, int nunber_bytes_spec = 1) = 0;
};

/// @brief Посылаемое сообщение первой категории
struct type1 : public abstract_message_type
{
private:
     int get_size_mes(int number_bite, int nunber_bytes_spec = 1) override final
    {
        if(number_bite>7) throw 1;
        int result_size = 0;
        switch (number_bite*nunber_bytes_spec)
        {
        case 1: result_size = sizeof(Pol1_1);
            break;
        case 2: result_size = sizeof(Pol1_2);
            break;
        case 3: result_size = sizeof(Pol1_3);
            break;
        case 4: result_size = sizeof(Pol1_4);
            break;
        case 5: result_size = sizeof(Pol1_5);
            break;
        case 6: result_size = sizeof(Pol1_6);
            break;
        case 7: result_size = sizeof(Pol1_7);
            break;
        case 8: result_size = sizeof(Pol1_8);
            break;
        case 9: result_size = sizeof(Pol1_9);
            break;
        case 10: result_size = sizeof(Pol1_10);
            break;
        case 11: result_size = sizeof(Pol1_11);
            break;
        case 12: result_size = sizeof(Pol1_12);
            break;
        case 13: result_size = sizeof(Pol1_13);
            break;
        case 14: result_size = sizeof(Pol1_14);
            break;
        }
        return result_size;
    }

public:
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
private:
     int get_size_mes(int number_bite, int nunber_bytes_spec = 1) override final
    {
        if(number_bite>7) throw 1;
        int result_size = 0;
        switch (number_bite*nunber_bytes_spec)
        {
        case 1: result_size = sizeof(Pol2_1);
            break;
        case 2: result_size = sizeof(Pol2_2);
            break;
        case 3: result_size = sizeof(Pol2_3);
            break;
        case 4: result_size = sizeof(Pol2_4);
            break;
        case 5: result_size = sizeof(Pol2_5);
            break;
        case 6: result_size = sizeof(Pol2_6);
            break;
        case 7: result_size = sizeof(Pol2_7);
            break;
        }
        return result_size;
    }

public:
    struct Pol2_1 : abstract_type
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