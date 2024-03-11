#pragma once

#ifndef STARFLEET_GAMELOADTASK_HPP
#define STARFLEET_GAMELOADTASK_HPP

#include "ResourceIdentifiers.hpp"
#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <array>
#include <map>

class GameLoadTask {
    
    public:
        
        GameLoadTask(TextureHolder&, FontHolder&);
        
        void execute();
        bool isFinished();
        
        std::pair<float, std::string> getCompletion();
        
    private:
        
        void runTask();
        void registerAssets();
        
    private:
        
        sf::Mutex mMutex;
        sf::Thread mThread;
        
        TextureHolder &mTextures;
        FontHolder &mFonts;
        
        std::string mResource;
        std::size_t mTextureIndex, mFontIndex;
        
        bool mIsFinished;
        
        std::map<Fonts::ID, std::array<std::string, 2>> fonts;
        std::map<Textures::ID, std::array<std::string, 2>> textures;
        
};

#endif