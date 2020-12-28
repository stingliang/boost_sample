// c++ stdlibrary
#include <iostream>
using std::cout;
using std::endl;

// bost library
#include <boost/version.hpp>
#include <boost/config.hpp>

int main(int argc, char * argv[])
{
	cout << BOOST_VERSION << endl;
	cout << BOOST_LIB_VERSION << endl;
	cout << BOOST_PLATFORM << endl;
	cout << BOOST_COMPILER << endl;
	cout << BOOST_STDLIB << endl;
}
