#include "Protocol_pak.h"

#pragma once

void Protocol_handler::set_title(Title tl)
{
}

void Protocol_handler::Make_message_for_send()
{
}

void Protocol_handler::clear_handler()
{
}

void Protocol_handler::set_type_mes(int type)
{
    this->header.uniq_type = type;
}

void Protocol_handler::set_protcol_version(int version_version)
{
    this->header.version_protocol = version_version;
}

void Protocol_handler::set_size_message(int size)
{
    this->header.size = size;
}

std::unique_ptr<char[]> Protocol_handler::get_send_buffer()
{
    return std::move(std::unique_ptr<char[]>());
}
