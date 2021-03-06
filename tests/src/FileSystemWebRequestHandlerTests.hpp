/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_FILESYSTEMWEBREQUESTHANDLERTESTS_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_FILESYSTEMWEBREQUESTHANDLERTESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class FileSystemWebRequestHandlerTests : public Ishiko::TestSequence
{
public:
    FileSystemWebRequestHandlerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void RunTest1(Ishiko::Test& test);
    static void RunTest2(Ishiko::Test& test);
    static void RunTest3(Ishiko::Test& test);
    static void RunTest4(Ishiko::Test& test);
    static void RunTest5(Ishiko::Test& test);
    static void RunTest6(Ishiko::Test& test);
};

#endif
