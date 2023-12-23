#include<Message_handler.h>

Message_handler::Message_handler(/* args */)
{
}

Message_handler::~Message_handler()
{
}

std::unique_ptr<Buffer> Message_handler::get_bytes_buffer()
{
    return std::unique_ptr<Buffer>();
}

void Message_handler::set_buffer(std::unique_ptr<Buffer> buff)
{
}
