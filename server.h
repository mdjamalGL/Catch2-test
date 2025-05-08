#pragma once

#include <string>
#include <vector>
#include <cstdint>

class IServer {
public:
    virtual ~IServer() = default;
    // virtual bool start(uint16_t port) = 0;
    // virtual void stop() = 0;
    virtual bool isRunning() = 0;
    // virtual void broadcast(const std::string& message) = 0;
    // virtual size_t connectionCount() const = 0;
};
