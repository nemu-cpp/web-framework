/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_MAPVIEWCONTEXT_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_MAPVIEWCONTEXT_HPP_

#include "ViewContext.hpp"
#include <map>
#include <string>

namespace Nemu
{

class MapViewContext : public ViewContext
{
public:
    Value getValue(const std::string& variable, Ishiko::Error& error) override;
    const std::map<std::string, Value> toMap() const noexcept override;

    std::map<std::string, Value>& map() noexcept;

private:
    std::map<std::string, Value> m_map;
};

}

#endif
