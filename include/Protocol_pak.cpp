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
    this->message_size = size;
}

std::unique_ptr<char[]> Protocol_handler::get_send_buffer()
{
    std::unique_ptr<char[]> buff(new char[this->Head_size+this->Title_size+this->sie_spec+this->message_size]);
    memcpy(buff.get(),&header,this->Head_size);
    memcpy(buff.get()+this->Head_size,&title,this->Title_size);
    // BUG: Важно проверить это место не уверен что правильно сработает 
    memcpy(buff.get()+this->Head_size+this->Title_size,&(specif.buffer.begin()),this->get_size_spec());
    // BUG:Не доделана упаковка тела сообщения 
    //memcpy(buff.get()+this->Head_size+this->Title_size+this->sie_spec,,this->message_size);
    return std::move(buff);
}

int Protocol_handler::get_size_spec()
{
    return this->specif.buffer.size();
}
