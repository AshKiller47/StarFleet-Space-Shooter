#pragma once

#ifndef STARFLEET_COMMANDQUEUE_HPP
#define STARFLEET_COMMANDQUEUE_HPP

#include "Command.hpp"
#include <queue>

class CommandQueue {
    
    public:
        
        void push(const Command&);
        
        Command pop();
        
        bool isEmpty() const;
        
    private:
        
        std::queue<Command> mQueue;
        
};

#endif