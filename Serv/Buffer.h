#pragma once

/// @brief Структура буфера 
struct Buffer
{
private:
    /// @brief Сообщение в виде набора байт
    std::unique_ptr<char []> buffer;
    /// @brief Размер сообщения в байтах
    int buffer_size = 0;
    /// @brief Тип сообщения в буфере 
    int type_message = 0;
    /// @brief Версия пртокола
    int Version_protocol = 0;
    bool emty_buff = true;

public:
    Buffer(char *a, int size)
    {
        if (a == nullptr)
            throw 1;
    }

    Buffer (std::unique_ptr<char[]> val,int size,int type,int version = 0){
        if(val.get() == nullptr) return;
        this->buffer_size = size;
        this->buffer = std::move(val);
        this->type_message = type;
        this->Version_protocol = version;
    }

    Buffer (Buffer &val) = delete;

    Buffer() = default;

    ~Buffer() = default;

    const int get_size() const
    {
        return buffer_size;
    }

    const char *get_buffer()
    {
        return buffer.get();
    }

    void set_buffer( std::unique_ptr<char []> value){
        if(value.get() == nullptr) return;
        buffer = std::move(value);
    }

    int get_type_message(){
        return this->type_message;
    }

    int get_version_protocol(){
        return this->Version_protocol;
    }

    Buffer * operator = (Buffer&) = delete;

};
