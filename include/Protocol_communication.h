#pragma once
#include<stdint.h>
#include<vector>

/// Протокол передачи сообщений переменной длинны

/// @brief Структура заголовка сообщения
struct Header{
    uint8_t uniq_type;
    uint8_t size;
    uint8_t version_protocol; 
};
/// @brief Контрольное сообщение 
struct Control_message{
    uint32_t id_abonent;
};
/// @brief Титл содержащий дополнительную техн информацию
struct Title {
    uint32_t sender_id;
    uint32_t sender_resiver;
};

struct specificatoin{
    char buffer ;
};

struct abstract_type{

};

struct abstract_message_type{
    public:

    virtual int get_size_mes(std::vector<char> specification);

};


/// @brief Посылаемое сообщение первой категории
struct type1: public abstract_message_type{


    int get_size_mes(std::vector<char> specification) override final{
        

    }


    struct Pol1_1:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_2:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_3:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_4:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_5:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_6:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_7:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol_prodolg_1{
        char byte;
    };

    struct Pol1_9:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_10:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_11:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_12:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_13:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_14:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_15:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol_prodolg_2{
        char byte;
    };

};

/// @brief Посылаемое сообщение второй категории
struct type2 {

      struct Pol1_1:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_2:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_3:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_4:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_5:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_6:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_7:abstract_type{
        uint8_t A1;
        uint8_t A2;
    };

};