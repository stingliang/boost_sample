/*
 * @Name: liangrui
 * @Date: 2020-12-28 11:09:20
 * @LastEditTime: 2020-12-28 11:47:54
 */
// c++ stdlib
#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// boost library
#include <boost/smart_ptr.hpp>
using namespace boost;

int main()
{
    //---------------
    // 构造shared_ptr
    //---------------

    // 接管原始指针
    shared_ptr<int> sp(new int(10));
    // 此时shared_ptr是指针唯一的额持有者
    assert(sp.unique());

    // 拷贝构造
    shared_ptr<int> sp1(sp);
    // shared_ptr<int> sp1 = sp;
    assert(sp == sp1 && sp.use_count() == 2);

    // 使用解引用操作符操作被指对象
    *sp1 = 100;

    // 停止使用shared_ptr
    sp.reset();

    // 使用工厂函数构造
    auto sp2 = make_shared<string>("make shared");
    auto sp3 = make_shared<vector<int>>(10, 2);
    assert(sp3 -> size() == 10);
}
