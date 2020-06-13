#include <iostream>
#include "spdlog/spdlog.h"
#include "libzmq/zmq.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "HelloWorld" << std::endl;
    spdlog::info("HelloWorld SPDLOG!");
    return 0;
}
