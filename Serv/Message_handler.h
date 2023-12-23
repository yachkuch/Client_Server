#pragma once
#include <iostream>
#include <memory>
#include <Buffer.h>
class Message_handler
{
private:
    
public:
    Message_handler();
    ~Message_handler();

static std::unique_ptr<Buffer> get_bytes_buffer();

static void set_buffer(std::unique_ptr<Buffer> buff);

};

