#include "StarFleet/SceneNode.hpp"
#include "StarFleet/Command.hpp"
#include "StarFleet/Utility.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <algorithm>

SceneNode::SceneNode(Category::Type category): mParent(nullptr), mWindowCenter(), mDefaultCategory(category), mChildren() {}

void SceneNode::removeWrecks() {
    
    auto wreckFieldBegin = std::remove_if(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::isMarkedForRemoval));
    
    mChildren.erase(wreckFieldBegin, mChildren.end()); std::for_each(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::removeWrecks));
    
}

void SceneNode::attachChild(Ptr child) { child->mParent = this; mChildren.push_back(std::move(child)); }

void SceneNode::update(sf::Time deltaTime, CommandQueue &commands) { updateCurrent(deltaTime, commands); updateChildren(deltaTime, commands); }

void SceneNode::setWindowCenter(sf::Vector2f windowCenter) { mWindowCenter = windowCenter; }

void SceneNode::onCommand(const Command &command, sf::Time deltaTime) { if(command.category & getCategory()) command.action(*this, deltaTime); for(Ptr &child: mChildren) child->onCommand(command, deltaTime); }

void SceneNode::checkNodeCollision(SceneNode &node, std::set<Pair> &collisionPairs) {
    
    if(this != &node && collision(*this, node) && !isDestroyed() && !node.isDestroyed()) collisionPairs.insert(std::minmax(this, &node)); for(Ptr &child: mChildren) child->checkNodeCollision(node, collisionPairs);
    
}

void SceneNode::checkSceneCollision(SceneNode &sceneGraph, std::set<Pair> &collisionPairs) {
    
    checkNodeCollision(sceneGraph, collisionPairs); for(Ptr &child: sceneGraph.mChildren) checkSceneCollision(*child, collisionPairs);
    
}

void SceneNode::interpolate(float alpha) { interpolateCurrent(alpha); for(Ptr &child: mChildren) child->interpolate(alpha); }

void SceneNode::saveCurrentState() { currentState(); for(Ptr &child: mChildren) child->saveCurrentState(); }

void SceneNode::savePreviousState() { previousState(); for(Ptr &child: mChildren) child->savePreviousState(); }

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node) {
    
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr &p) -> bool { return p.get() == &node; }); // assert(found != mChildren.end());
    
    Ptr result = std::move(*found); result->mParent = nullptr; mChildren.erase(found); return result;
    
}

sf::Vector2f SceneNode::getWorldPosition() const { return getWorldTransform() * sf::Vector2f(); }

sf::Transform SceneNode::getWorldTransform() const {
    
    sf::Transform transform = sf::Transform::Identity; for(const SceneNode *node = this; node != nullptr; node = node->mParent) transform = node->getTransform() * transform; return transform;
    
}

float SceneNode::getAzimuth() const { return 0.f; }

bool SceneNode::isDestroyed() const { return false; }

bool SceneNode::isMarkedForRemoval() const { return isDestroyed(); }

unsigned int SceneNode::getCategory() const { return mDefaultCategory; }

sf::FloatRect SceneNode::getBoundingRect() const { return sf::FloatRect(); }

sf::Vector2f SceneNode::getWindowCenter() const { return mWindowCenter; }

void SceneNode::updateChildren(sf::Time deltaTime, CommandQueue &commands) { for(Ptr &child: mChildren) child->update(deltaTime, commands); }

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const { for(const Ptr &child: mChildren) child->draw(target, states); }

void SceneNode::drawBoundingRect(sf::RenderTarget &target, sf::RenderStates states) const {
    
    sf::FloatRect rect = getBoundingRect(); sf::RectangleShape shape;
    
    shape.setSize(sf::Vector2f(rect.width, rect.height)); shape.setPosition(sf::Vector2f(rect.left, rect.top));
    
    shape.setOutlineThickness(1.5f); shape.setOutlineColor(sf::Color::White); shape.setFillColor(sf::Color::Transparent);
    
    target.draw(shape);
    
}

void SceneNode::updateCurrent(sf::Time deltaTime, CommandQueue &commands) {}

void SceneNode::currentState() {}

void SceneNode::previousState() {}

void SceneNode::interpolateCurrent(float alpha) {}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    
    states.transform *= getTransform(); drawCurrent(target, states); drawChildren(target, states); // drawBoundingRect(target, states);
    
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {}

bool collision(const SceneNode &node_1, const SceneNode &node_2) { return node_1.getBoundingRect().intersects(node_2.getBoundingRect()); }

float angularDistance(const SceneNode &node_1, const SceneNode &node_2) {
    
    float azimuth = std::abs(toDegree(node_1.getAzimuth() - node_2.getAzimuth())); while(azimuth > 360.f) azimuth -= 360.f; if(azimuth > 180.f) return toRadian(360.f - azimuth); else return toRadian(azimuth);
    
}

// void SceneNode::update(sf::Time deltaTime, const sf::Vector2f &windowCenter) { updateCurrent(deltaTime, windowCenter); updateChildren(deltaTime, windowCenter); }

// void SceneNode::updateChildren(sf::Time deltaTime, const sf::Vector2f &windowCenter) { for(Ptr &child: mChildren) child->update(deltaTime, windowCenter); }

// void SceneNode::updateCurrent(sf::Time deltaTime, const sf::Vector2f &windowCenter) {}