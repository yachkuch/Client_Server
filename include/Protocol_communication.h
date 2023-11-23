#pragma once
#include<stdint.h>

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

struct Title {
    uint32_t sender_id;
    uint32_t sender_resiver;
};

struct specificatoin{
    char *buffer = nullptr;
};

struct abstract_type{

};

struct type1 : abstract_type{
    struct Pol1_1{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_2{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_3{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_4{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_5{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_6{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_7{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol_prodolg_1{
        char byte;
    };

    struct Pol1_9{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_10{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_11{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_12{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_13{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_14{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol1_15{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol_prodolg_2{
        char byte;
    };

};

struct type2 : abstract_type{

      struct Pol1_1{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_2{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_3{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_4{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_5{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_6{
        uint8_t A1;
        uint8_t A2;
    };

    struct Pol2_7{
        uint8_t A1;
        uint8_t A2;
    };

};