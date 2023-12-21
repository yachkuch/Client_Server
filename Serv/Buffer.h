#pragma once

// TODO Написать нормально буффер для работы с данными обязательно на умном указателе
/// @brief Структура буфера привести указатель на буфер к умному указателю
struct Buffer
{
private:
    std::unique_ptr<char []> buffer;
    int buffer_size = 0;
    bool emty_buff = true;

public:
    Buffer(char *a, int size)
    {
        if (a == nullptr)
            throw 1;
    }

    Buffer (std::unique_ptr<char[]> val,int size){
        if(val.get() == nullptr) return;
        this->buffer_size = size;
        this->buffer = std::move(val);
    }
    Buffer (Buffer &val) = delete;

    Buffer() = default;

    ~Buffer()
    {
        
    }

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
