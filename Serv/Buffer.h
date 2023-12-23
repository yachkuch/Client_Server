#pragma once

/// @brief Структура буфера 
struct Buffer
{
private:
    /// @brief Сообщение в виде набора байт
    std::unique_ptr<char []> buffer;
    /// @brief Байтовый набор хедера
    std::unique_ptr<char []> header;
    /// @brief Размер сообщения в байтах
    int buffer_size = 0;
    bool emty_buff = true;

public:

    Buffer (std::unique_ptr<char[]> val,int size,std::unique_ptr<char[]> Header){
        if(val.get() == nullptr) return;
        this->buffer_size = size;
        this->buffer = std::move(val);
        this->header = std::move(Header);
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

    Buffer * operator = (Buffer&) = delete;

};
