#include <iostream>

#include "serial/serial.h"

/**
 * 遍历串口的函数
 * */
void enumerate_ports()
{
    std::vector<serial::PortInfo> devices_found = serial::list_ports();

    auto iter = devices_found.begin();

    while (iter != devices_found.end())
    {
        serial::PortInfo device = *iter++;

        printf("(%s, %s, %s)\n", device.port.c_str(), device.description.c_str(),
               device.hardware_id.c_str());
    }
}

int main(int argc, char const *argv[])
{
    enumerate_ports();
    return 0;
}
