#include <utility>

int main()
{
    int i=42;
    const auto f = [i{std::move(i)}] { return i; };
    
    return f();
}
