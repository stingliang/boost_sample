/*
 * @Name: liangrui
 * @Date: 2020-12-28 11:09:20
 * @LastEditTime: 2020-12-28 21:38:09
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
    // ----------
    // shared_ptr
    // ----------

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

    // ----------
    // weak_ptr
    // ----------

    shared_ptr<int> sp4(new int(10));
    assert(sp4.use_count() == 1);

    // 从shared_ptr构造
    weak_ptr<int> wp(sp4);
    assert(wp.use_count() == 1);
    assert(!wp.empty());

    // 从weak_ptr获取shared_ptr
    if(!wp.expired())
    {
        // 获得一个shared_ptr
        shared_ptr<int> sp = wp.lock();
        *sp = 100;
        assert(wp.use_count() == 2);
    }

    assert(wp.use_count() == 1);
    // 智能指针失效
    sp4.reset();
    assert(wp.expired());
    // weak_ptr将获得一个空指针
    assert(!wp.lock());

    // -------------
    // 对象自我管理
    // -------------
    class self_shared: public enable_shared_from_this<self_shared>
    {
    public:
        self_shared(int n):num(n){}
        int num;
        void print()
        {
            cout << "self_shared:" << num << endl;
        }
    };

    auto sp5 = make_shared<self_shared>(313);
    sp5 -> print();

    auto sp6 = sp5->shared_from_this();
    sp6 -> num = 100;
    sp6 -> print();

    // 错误用法
    // self_shared ss(100);
    // auto p = ss.shared_from_this();
}
