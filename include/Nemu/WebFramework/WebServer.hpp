/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_WEBSERVER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_WEBSERVER_HPP_

#include "WebRequestHandler.hpp"
#include <Nemu/Core.hpp>

namespace Nemu
{

class WebServer : public Server
{
public:
    WebRequestHandler* m_requestHandler;
};

}

#endif
