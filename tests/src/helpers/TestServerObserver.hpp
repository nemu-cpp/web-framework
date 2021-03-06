/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTSERVEROBSERVER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTSERVEROBSERVER_HPP_

#include <Nemu/Core.hpp>
#include <mutex>
#include <vector>
#include <tuple>

class TestServerObserver : public Nemu::Server::Observer
{
public:
    enum EEventType
    {
        eConnectionOpened,
        eConnectionClosed
    };

    const std::vector<std::tuple<EEventType, const Nemu::Server*, std::string>>& connectionEvents() const;

    void onConnectionOpened(const Nemu::Server& source, const std::string& sourceAddress) override;
    void onConnectionClosed(const Nemu::Server& source, const std::string& sourceAddress) override;

private:
    std::mutex m_connectionEventsMutex;
    std::vector<std::tuple<EEventType, const Nemu::Server*, std::string>> m_connectionEvents;
};

#endif
