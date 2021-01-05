/*
 * @Name: liangrui
 * @Date: 2020-12-31 14:12:45
 * @LastEditTime: 2020-12-31 14:24:42
 */
#define COUT(str) (cout << "-------------\n" \
                        << str \
                        << "\n-------------" \
                        << endl)

// c++ stdlib
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <cmath>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::list;

// --------------------boost assert--------------------
#include <boost/assert.hpp>
double func(int x)
{
    BOOST_ASSERT_MSG(x != 0, "divided by zero");
    return 1.0/x; 
}
void assertTest()
{
    auto result = func(5);
    cout << "func(1) passed. Result: " << result << endl;
    func(0);
}

int main()
{
    COUT("assert");
    assertTest();
}
