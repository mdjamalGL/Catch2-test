#pragma once
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

class Session
{
    private:
    std::string session_id;
    std::string session_url;
    std::string window_id;
    std::string player_type;

    public:
    Session() = delete;
    Session(std::string data);
    std::string get_session_id();
    std::string get_session_url();
    std::string get_window_id();
    std::string get_player_type();
    void print_details();
    
};

