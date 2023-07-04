//
// Created by carlo on 7/2/2023.
//
#include <iostream>
#include "host.h"


std::string getDeviceLocalIp() {
    asio::io_service ioService;
    asio::ip::tcp::resolver resolver(ioService);
    return resolver.resolve(asio::ip::host_name(), "")->endpoint().address().to_string();
}
