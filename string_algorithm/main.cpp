/*
 * @Name: liangrui
 * @Date: 2020-12-31 09:26:38
 * @LastEditTime: 2020-12-31 13:47:01
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

// --------------------lexical_cast--------------------
#include <boost/lexical_cast.hpp>
void lexicalCastTest()
{
    using namespace boost;

    // string -> int/long
    int x = lexical_cast<int>("100");
    long y = lexical_cast<long>("2000");

    // string -> float/double
    float pai = lexical_cast<float>("3.14159e5");
    double e = lexical_cast<double>("2.71828");
    cout << "pai = " << pai
         << "e = " << e << endl;

    // int -> string
    string str = lexical_cast<string>(456);
    cout << "str = " << str << endl;

    // 直接作为左值输出
    cout << lexical_cast<string>(0.618) << endl;
    cout << lexical_cast<string>(0x10) << endl;
}

// --------------------format--------------------
#include <boost/format.hpp>
void formatTest()
{
    using namespace boost;

    // 简单例子
    cout << format("%s:%d+%d=%d\n") %"sum" %1 %2 %(1+2);
    format fmt("( %1% + %2% ) * %2% = %3%\n");
    fmt %2 %5;
    fmt %((2+5)*5);
    cout << fmt.str();

    // 格式化语法
    // %05d：输出宽度为5的整数，不足位用0填充
    // %-8.3f：输出左对齐，总宽度为8，小数位为3位的浮点数
    // %10s：输出10位的字符串，不足位用空格填充
    // %05X：输出宽度为5的大写十六进制整数，不足位用0填充
    format fmt1("%05d\t%-8.3f\t% 10s\t%05x\n");
    cout << fmt1 %62 %2.236 %"123456789" %48;

    // %|spec|：与printf格式选项的功能相同，但其两边增加了竖线分隔，可以更好地区分格式化选项与普通字符
    // %N%：标记第N个参数，相当于占位符，不带任何其他的格式化选项
    format fmt2("%|05d|\t%|-8.3f|\t%| 10s|\t%|05x|\n");
    cout << fmt1 %62 %2.236 %"123456789" %48;
}

// --------------------string_ref--------------------
#include <boost/utility/string_ref.hpp>
void stringRefTest()
{
    using namespace boost;
    const char * ch = "Hello,World!";

    // 标准字符串，有拷贝成本
    string str(ch);
    // 直接构造
    string_ref s0("Hello,World!");
    cout << "s0 = " << s0 << endl;
    // 字符数组构造，0拷贝
    string_ref s1(ch);
    // 标准字符串构造，0拷贝
    string_ref s2(str);
    assert(s0 == s1 && s1 == s2 && s1 == ch && s2 == str);

    // 截取部分字符串构造
    string_ref s3(ch, 4);
    assert(s3 == str.substr(0,4));

    // 空构造
    string_ref s4, s5;
    s4 = ch;
    s5 = str;
    assert(s4 == s5);
}

// --------------------string_algo--------------------
#include <boost/algorithm/string.hpp>
void stringAlgoTest()
{
    using namespace boost;
    // 大小写转换
    string str("Hello,World!");
    cout << str << endl;
    cout << to_upper_copy(str) << endl;
    cout << str << endl;
    to_upper(str);
    cout << str << endl;
}

int main()
{
    // lexcial cast
    COUT("lexcial_cast");
    lexicalCastTest();

    //format
    COUT("format");
    formatTest();

    // string_ref
    COUT("string ref");
    stringRefTest();

    // string algo
    COUT("string algo");
    stringAlgoTest();
}