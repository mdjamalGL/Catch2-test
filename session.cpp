#include "session.h"

Session::Session(std::string req_string)
{
    json req = json::parse(req_string);
    if(req.contains("id"))
    {
        session_id = req["id"];
    }
    else
    {
        session_id = "";
    }

    if(req.contains("url"))
    {
        session_url = req["url"];
    }
    else
    {
        session_url = "";
    }

    if(req.contains("window_id"))
    {
        window_id = req["window_id"];
    }
    else
    {
        window_id = "";
    }

    if(req.contains("player_type"))
    {
        player_type = req["player_type"];
    }
    else
    {
        player_type = "";
    }
}

std::string Session::get_session_id()
{
    return session_id;
}

std::string Session::get_session_url()
{
    return session_url;
}

std::string Session::get_window_id()
{
    return window_id;
}

std::string Session::get_player_type()
{
    return player_type;
}

void Session::print_details()
{
    std::cout<<std::endl<<"Session Details\n";
    std::cout<<"\tSession Id : "<<session_id<<std::endl;
    std::cout<<"\tSession Url : "<<session_url<<std::endl;
    std::cout<<"\tWindow Id : "<<window_id<<std::endl;
    std::cout<<"\tPlayer Type: "<<player_type<<std::endl;
}