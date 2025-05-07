#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>
#include <nlohmann/json.hpp>
#include "session.h"

using json = nlohmann::json;
using Catch::Matchers::StartsWith;
using Catch::Matchers::ContainsSubstring;

//Test api parameters
std::string m_id = "S_V1-102";
std::string m_url = "https://media.database/v2/BppG_qNKbyg?si=K6EpT_GTcxBRSSfH";
std::string m_window_id = "Win102";
std::string m_player_type = "VLC";

//Request mock Json object
json m_req = 
{
    {"id", m_id},
    {"url", m_url},
    {"window_id", m_window_id},
    {"player_type", m_player_type}
};

TEST_CASE( "Session Class Unit Test", "[Session]" ) {
    
    Session mock_session(m_req.dump());

    
    SECTION("ID format", "[check session and window id prefix format]") {
        REQUIRE_THAT(mock_session.get_session_id(), StartsWith("S_V1-"));
        REQUIRE_THAT(mock_session.get_window_id(), StartsWith("Win"));
    }

    SECTION("Player Type", "[check player type is among known values]") {
        REQUIRE(((mock_session.get_player_type() == "VLC") || 
                (mock_session.get_player_type() == "GOM") || 
                (mock_session.get_player_type() == "KMP") 
        ));
    }

    SECTION("Url Check", "[check url's domain name correctness]") {
        REQUIRE_THAT(mock_session.get_session_url(), ContainsSubstring("https://media.database/v2"));
    }
    SECTION("Object Population from json", "[check if session object got populated successfully]") {
        CHECK(mock_session.get_session_id() == m_id);
        CHECK(mock_session.get_session_url() == m_url);
        CHECK(mock_session.get_window_id() == m_window_id);
        CHECK(mock_session.get_player_type() == m_player_type);
    }
    
}
