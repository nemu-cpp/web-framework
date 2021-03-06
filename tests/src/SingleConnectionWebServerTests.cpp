/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "SingleConnectionWebServerTests.hpp"
#include "helpers/TestServerObserver.hpp"
#include "helpers/TestWebRequestHandler.hpp"
#include "Nemu/WebFramework/SingleConnectionWebServer.hpp"
#include <boost/filesystem.hpp>
#include <Ishiko/HTTP.hpp>
#include <Ishiko/Logging.hpp>
#include <Ishiko/Networking.hpp>
#include <sstream>

using namespace Ishiko;
using namespace Nemu;

SingleConnectionWebServerTests::SingleConnectionWebServerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "SingleConnectionWebServer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("start test 1", StartTest1);
    append<HeapAllocationErrorsTest>("Request test 1", RequestTest1);
    append<HeapAllocationErrorsTest>("Request test 2", RequestTest2);
    append<HeapAllocationErrorsTest>("Request test 3", RequestTest3);
}

void SingleConnectionWebServerTests::ConstructorTest1(Test& test)
{
    Error error;

    NullLoggingSink sink;
    Logger logger(sink);

    SingleConnectionWebServer server(IPv4Address::Localhost(), 0, logger, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_PASS();
}

void SingleConnectionWebServerTests::StartTest1(Test& test)
{
    Error error;

    NullLoggingSink sink;
    Logger logger(sink);

    SingleConnectionWebServer server(IPv4Address::Localhost(), 8585, logger, error);

    ISHIKO_TEST_FAIL_IF(error);

    server.start();
    server.stop();
    server.join();

    ISHIKO_TEST_PASS();
}

void SingleConnectionWebServerTests::RequestTest1(Test& test)
{
    std::shared_ptr<TestServerObserver> observer = std::make_shared<TestServerObserver>();
    Error error;
    StreamLoggingSink sink(std::cout);
    Logger logger(sink);
    SingleConnectionWebServer server(IPv4Address::Localhost(), 8089, logger, error);

    TestWebRequestHandler requestHandler;
    server.m_requestHandler = &requestHandler;

    server.start();

    boost::filesystem::path outputPath =
        test.context().getOutputPath("SingleConnectionWebServerTests_RequestTest1.bin");
    std::ofstream responseFile(outputPath.string(), std::ios::out | std::ios::binary);
    // TODO: this seems to leak memory but only the first time it is used, does Boost allocate some global variables?
    HTTPClient::Get(IPv4Address::Localhost(), 8089, "/", responseFile, error);

    ISHIKO_TEST_FAIL_IF(error);

    responseFile.close();

    server.stop();
    server.join();

    const std::vector<std::tuple<TestServerObserver::EEventType, const Nemu::Server*, std::string>>& events =
        observer->connectionEvents();

    /*
    * TODO
    ISHIKO_TEST_ABORT_IF_NEQ(events.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[0]), TestServerObserver::eConnectionOpened);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[0]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]).substr(0, 10), "127.0.0.1:");
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[1]), TestServerObserver::eConnectionClosed);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[1]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]), std::get<2>(events[1]));
    */

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("SingleConnectionWebServerTests_RequestTest1.bin");
    ISHIKO_TEST_PASS();
}

void SingleConnectionWebServerTests::RequestTest2(Test& test)
{
    std::shared_ptr<TestServerObserver> observer = std::make_shared<TestServerObserver>();
    Error error;
    StreamLoggingSink sink(std::cout);
    Logger logger(sink);
    SingleConnectionWebServer server(IPv4Address::Localhost(), TCPServerSocket::AnyPort, logger, error);

    TestWebRequestHandler requestHandler;
    server.m_requestHandler = &requestHandler;

    server.start();

    boost::filesystem::path outputPath1 =
        test.context().getOutputPath("SingleConnectionWebServerTests_RequestTest2_1.bin");
    std::ofstream responseFile1(outputPath1.string(), std::ios::out | std::ios::binary);
    HTTPClient::Get(IPv4Address::Localhost(), server.socket().port(), "/", responseFile1, error);
    responseFile1.close();

    ISHIKO_TEST_FAIL_IF(error);

    boost::filesystem::path outputPath2 =
        test.context().getOutputPath("SingleConnectionWebServerTests_RequestTest2_2.bin");
    std::ofstream responseFile2(outputPath2.string(), std::ios::out | std::ios::binary);
    HTTPClient::Get(IPv4Address::Localhost(), server.socket().port(), "/", responseFile2, error);
    responseFile2.close();

    ISHIKO_TEST_FAIL_IF(error);

    server.stop();
    server.join();

    const std::vector<std::tuple<TestServerObserver::EEventType, const Nemu::Server*, std::string>>& events =
        observer->connectionEvents();

    /*
    * TODO
    ISHIKO_TEST_ABORT_IF_NEQ(events.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[0]), TestServerObserver::eConnectionOpened);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[0]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]).substr(0, 10), "127.0.0.1:");
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[1]), TestServerObserver::eConnectionClosed);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[1]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]), std::get<2>(events[1]));
    */

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("SingleConnectionWebServerTests_RequestTest2_1.bin");
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("SingleConnectionWebServerTests_RequestTest2_2.bin");
    ISHIKO_TEST_PASS();
}

void SingleConnectionWebServerTests::RequestTest3(Test& test)
{
    std::shared_ptr<TestServerObserver> observer = std::make_shared<TestServerObserver>();
    Error error;
    StreamLoggingSink sink(std::cout);
    Logger logger(sink);
    SingleConnectionWebServer server(IPv4Address::Localhost(), TCPServerSocket::AnyPort, logger, error);
    Port port = server.socket().port();

    TestWebRequestHandler requestHandler;
    server.m_requestHandler = &requestHandler;
 
    // TODO: we should try to connect before the socket is opened but at the moment with my blocking HTTPClient I can't
    // do that

    server.start();

    boost::filesystem::path outputPath =
        test.context().getOutputPath("SingleConnectionWebServerTests_RequestTest3.bin");
    std::ofstream responseFile(outputPath.string(), std::ios::out | std::ios::binary);
    HTTPClient::Get(IPv4Address::Localhost(), port, "/", responseFile, error);

    ISHIKO_TEST_FAIL_IF(error);

    responseFile.close();

    server.stop();

    server.join();

    // At this stage the server is stopped but not destroyed. Verify that attempts to connect fail.

    // TODO
    const std::vector<std::tuple<TestServerObserver::EEventType, const Nemu::Server*, std::string>>& events =
        observer->connectionEvents();

    std::stringstream output;
    HTTPClient::Get(IPv4Address::Localhost(), port, "/", output, error);

    ISHIKO_TEST_FAIL_IF_NOT(error);
    // TODO: check error type

    /*
    * TODO
    ISHIKO_TEST_ABORT_IF_NEQ(events.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[0]), TestServerObserver::eConnectionOpened);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[0]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]).substr(0, 10), "127.0.0.1:");
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[1]), TestServerObserver::eConnectionClosed);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[1]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]), std::get<2>(events[1]));
    */

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("SingleConnectionWebServerTests_RequestTest3.bin");
    ISHIKO_TEST_PASS();
}
