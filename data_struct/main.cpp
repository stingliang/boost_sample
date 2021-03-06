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

// 打印STL-vector
template<typename T>
void printStl(vector<T>& v)
{
    for(auto elem : v)
        cout << elem << endl;
}
// 打印STL-map
template<typename T1, typename T2>
void printStl(map<T1,T2>& m)
{
    for(auto elem : m)
        cout << elem.first << " | " << elem.second << endl;
}

// --------------------array--------------------
#include <boost/array.hpp>
void arrayTest()
{
    using namespace boost;
    array<int, 10> ar;  // 一个大小为10的数组
    ar.assign(0);

    ar[0] = 1;  // 使用[]操作符访问元素
    ar.back() = 10; // 访问最后一个元素

    int i = 0;
    for(auto elem : ar)
        cout << "ar[" << i++ << "] " << elem << endl;
}
// --------------------dynamic bitset--------------------
#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
void dynamicBitsetTest()
{
    using namespace boost;
    dynamic_bitset<> db1;   // 空的dyncmic_bitset
    dynamic_bitset<> db2(10);   // 大小为10的dyncmic_bitset
    dynamic_bitset<> db3(0x16, BOOST_BINARY(10101));    // 大小为22的dyncmic_bitset
    dynamic_bitset<> db4(string("0100101010011101001001"));   // 字符串构造
    dynamic_bitset<> db5(db3);  // 拷贝构造
    
    cout << std::hex << db4.to_ulong() << endl;  // 转换为整数
    for(int i = 0; i < db4.size(); i++)
        cout << db4[i];
    cout << endl;

}
// --------------------unordered--------------------
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/assign.hpp>
void unorderedTest()
{
    using namespace boost;
    // 散列集合用法示例
    unordered_set<int> s = {1, 2, 3, 4, 5};

    for(auto x : s)
    {
        cout << x << ",";
    }
    cout << endl;
    cout << s.size() << endl;   // 获取容器大小

    s.clear();  // 清空集合
    cout << s.empty() << endl;  // 集合判空

    s.insert(8);
    s.insert(45);
    cout << s.size() << endl;
    cout << *s.find(8) << endl; // 查找元素

    s.erase(45);    // 删除元素

    using namespace boost::assign;
    unordered_set<int> us1 = list_of(1)(2)(3);
    unordered_set<int> us2 = list_of(3)(2)(1);
    BOOST_ASSERT(us1 == us2);
}

int main()
{
    COUT("array");
    arrayTest();

    COUT("dynamic bitset");
    dynamicBitsetTest();

    COUT("unorder set");
    unorderedTest();
}