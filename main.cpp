#include <iostream>
#include "session.h"

int main(int argc, char* argv[])
{   
    std::cout<<"Inside Main of App"<<std::endl;
    if(argc == 1)
    {
        std::cout<<"Too less parameter\nFormat : ./app {json_string}\n";
    }
    std::string string_req = std::string(argv[1]);
    
    Session session(string_req);
    session.print_details();
    
    return 0;
}