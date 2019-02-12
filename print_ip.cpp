#include <iostream>
#include <vector>

template <typename T>
decltype(std::declval<T>().begin(), std::declval<T>().end(), void())
print_ip(T ip)
{
    for (unsigned i = 0; i < ip.size(); ++i)
        std::cout << (i > 0 ? "." : "") << ip[i]; 
    std::cout << std::endl;
}

template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
void print_ip(T ip)
{
    using unsig_type = typename std::template make_unsigned<T>::type;
    unsig_type out = ip;
    size_t n = sizeof(ip);
    short r_shift = n * 8 - 8, l_shift = 0;
    if (n == 1)
        std::cout << (unsigned)out;
    else
        for (size_t i = 0; i < n; ++i){
            out = ip << l_shift;
            out = out >> r_shift;
            if (l_shift)
                std::cout << ".";
            std::cout << out;
            l_shift += 8;
        }
        std::cout << std::endl;
}

void print_ip(std::string ip)
{
        std::cout << ip << std::endl;
}

int main(){
    char a = -1;
    print_ip(a);
    short b = 0;
    print_ip(b);
    int c = 2130706433;
    print_ip(c);
    long d = 8875824491850138409;
    print_ip(d);

    return 0;
}