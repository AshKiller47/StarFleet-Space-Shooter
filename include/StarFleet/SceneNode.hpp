#pragma once

#ifndef STARFLEET_SCENENODE_HPP
#define STARFLEET_SCENENODE_HPP

#include "Category.hpp"
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <memory>
#include <vector>
#include <set>

struct Command; class CommandQueue;

class SceneNode: public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
    
    public:
        
        typedef std::unique_ptr<SceneNode> Ptr;
        typedef std::pair<SceneNode*, SceneNode*> Pair;
        
    public:
        
        explicit SceneNode(Category::Type category = Category::None);
        
        void removeWrecks();
        void attachChild(Ptr);
        void setWindowCenter(sf::Vector2f);
        void update(sf::Time, CommandQueue&);
        void onCommand(const Command&, sf::Time);
        void checkNodeCollision(SceneNode&, std::set<Pair>&);
        void checkSceneCollision(SceneNode&, std::set<Pair>&);
        
        void interpolate(float);
        void saveCurrentState();
        void savePreviousState();
        
        // void update(sf::Time, const sf::Vector2f&);
        
        Ptr detachChild(const SceneNode&);
        
        sf::Vector2f getWorldPosition() const;
        sf::Transform getWorldTransform() const;
        
        virtual float getAzimuth() const;
        virtual bool isDestroyed() const;
        virtual bool isMarkedForRemoval() const;
        virtual unsigned int getCategory() const;
        
        virtual sf::FloatRect getBoundingRect() const;
        
    protected:
        
        sf::Vector2f getWindowCenter() const;
        
    private:
        
        void updateChildren(sf::Time, CommandQueue&);
        
        // void updateChildren(sf::Time, const sf::Vector2f&);
        
        void drawChildren(sf::RenderTarget&, sf::RenderStates) const;
        void drawBoundingRect(sf::RenderTarget&, sf::RenderStates) const;
        
        virtual void updateCurrent(sf::Time, CommandQueue&);
        
        virtual void currentState();
        virtual void previousState();
        virtual void interpolateCurrent(float);
        
        // virtual void updateCurrent(sf::Time, const sf::Vector2f&);
        
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;
        virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
        
    private:
        
        SceneNode *mParent;
        sf::Vector2f mWindowCenter;
        Category::Type mDefaultCategory;
        
        std::vector<Ptr> mChildren;
        
};

bool collision(const SceneNode&, const SceneNode&);
float angularDistance(const SceneNode&, const SceneNode&);

#endif