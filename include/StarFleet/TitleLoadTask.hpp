#pragma once

#ifndef STARFLEET_TITLELOADTASK_HPP
#define STARFLEET_TITLELOADTASK_HPP

#include "ResourceIdentifiers.hpp"
#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>
#include <string>
#include <map>

class TitleLoadTask {
    
    public:
        
        TitleLoadTask(TextureHolder&, FontHolder&);
        
        void execute();
        bool isFinished();
        float getCompletion();
        
    private:
        
        void runTask();
        void registerAssets();
        
    private:
        
        sf::Mutex mMutex;
        sf::Thread mThread;
        
        TextureHolder &mTextures;
        FontHolder &mFonts;
        
        std::size_t mTextureIndex, mFontIndex;
        
        bool mIsFinished;
        
        std::map<Fonts::ID, std::string> fonts;
        std::map<Textures::ID, std::string> textures;
        
};

#endif