#pragma once

#ifndef STARFLEET_WORLD_HPP
#define STARFLEET_WORLD_HPP

#include "Player.hpp"
#include "SceneNode.hpp"
#include "Spacecraft.hpp"
#include "CommandQueue.hpp"
#include "ResourceHolder.hpp"
// #include "NodeButton.hpp"
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class World: private sf::NonCopyable {
    
    public:
        
        enum GameMode { Classic, Accelerated };
        
    public:
        
        explicit World(sf::RenderWindow&, TextureHolder&, FontHolder&);
        
        void draw();
        void update(sf::Time);
        void setGameMode(Player::GameMode);
        
        void interpolate(float);
        void saveCurrentState();
        void savePreviousState();
        
        bool hasAliveMaster();
        bool hasAlivePlayer();
        
        sf::Time playerSurvivalTime();
        CommandQueue& getCommandQueue();
        
        // NodeButton& getButtonReference();
        
    private:
        
        void addEnemies();
        void buildScene();
        void spawnShooters();
        void spawnWreckers();
        
        void guideMissiles();
        void accelerateWorld();
        void handleCollisions();
        void handleMasterCollision();
        
        void checkAliveEnemies();
        void destroyEntitiesOutsideView();
        
        // void addCloseButton();
        // void addEscortSpacecraft();
        
        void addEnemy(Spacecraft::Type, float, float);
        
        sf::FloatRect getViewBounds() const;
        
    private:
        
        struct SpawnPoint {
            
            SpawnPoint(Spacecraft::Type type, float radius, float azimuth): type(type), radius(radius), azimuth(azimuth) {}
            
            Spacecraft::Type type; float radius, azimuth;
            
        };
        
        enum Layer { Background, Space, LayerCount };
        
        // enum Layer { Background, Air, Static, LayerCount };
        
    private:
        
        sf::RenderWindow &mWindow;
        sf::View mWorldView;
        sf::FloatRect mWorldBounds;
        sf::Clock mWorldClock, mEnemyClock;
        
        TextureHolder &mTextures;
        FontHolder &mFonts;
        GameMode mGameMode;
        SceneNode mSceneGraph;
        CommandQueue mCommandQueue;
        
        Spacecraft *mMasterSpacecraft;
        Spacecraft *mPlayerSpacecraft_1;
        Spacecraft *mPlayerSpacecraft_2;
        Spacecraft *mAlliedSpacecraft_1;
        Spacecraft *mAlliedSpacecraft_2;
        
        float mRadius, mPickupVelocity; bool mIsAccelerated, aliveEnemyCheck;
        
        const sf::Vector2f mWindowCenter; sf::Vector2f previousView, currentView;
        
        // NodeButton *mCloseButton;
        
        std::vector<Spacecraft*> mActiveEnemies;
        std::vector<SpawnPoint> mEnemySpawnPoints;
        std::array<SceneNode*, LayerCount> mSceneLayers;
        
};

bool matchesCategories(SceneNode::Pair&, Category::Type, Category::Type);

#endif