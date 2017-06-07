#include <utility>
#include <iostream>
#ifdef __MINGW32__
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

int main()
{    
    std::cout << fs::current_path() << '\n';
}
