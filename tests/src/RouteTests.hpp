/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_ROUTETESTS_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_ROUTETESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class RouteTests : public Ishiko::TestSequence
{
public:
    RouteTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ConstructorTest2(Ishiko::Test& test);
};

#endif
