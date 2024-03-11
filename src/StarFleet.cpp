#include "StarFleet/Application.hpp"
// #include "StarFleet/Game.hpp"
#include <iostream>

int main() {
    
    try { std::unique_ptr<Application> application = std::unique_ptr<Application>(new Application()); application->run(); }
    
    // try { std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game()); game->run(); }
    
    catch(std::exception &exp) { std::cout << "\nEXCEPTION: " << exp.what() << "\n"; }
    
}