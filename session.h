#pragma once
#include <nlohmann/json.hpp>
#include <iostream>
#include "server.h"

using json = nlohmann::json;

class Server : public IServer
{
    public : 
    Server();
    bool isRunning();
    bool is_running;
};
class Session
{
    private:
    std::string session_id;
    std::string session_url;
    std::string window_id;
    std::string player_type;
    IServer *_server;

    public:
    Session() = delete;
    Session(std::string data, IServer *serv);
    bool start_session();
    std::string get_session_id();
    std::string get_session_url();
    std::string get_window_id();
    std::string get_player_type();
    void print_details();
    
};

