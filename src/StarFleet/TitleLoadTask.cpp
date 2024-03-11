#include "StarFleet/TitleLoadTask.hpp"
#include "StarFleet/ResourceHolder.hpp"

TitleLoadTask::TitleLoadTask(TextureHolder &textures, FontHolder &fonts): mThread(&TitleLoadTask::runTask, this), mTextures(textures), mFonts(fonts), mTextureIndex(0), mFontIndex(0), mIsFinished(false) {
    
    registerAssets();
    
}

void TitleLoadTask::execute() { mIsFinished = false; mThread.launch(); }

bool TitleLoadTask::isFinished() { sf::Lock lock(mMutex); return mIsFinished; }

float TitleLoadTask::getCompletion() { sf::Lock lock(mMutex); return (mTextureIndex + mFontIndex) / (float)(textures.size() + fonts.size()); }

void TitleLoadTask::runTask() {
    
    for(std::map<Textures::ID, std::string>::iterator it = textures.begin(); it != textures.end(); it++) { sf::Lock lock(mMutex); mTextures.load(it->first, it->second); mTextureIndex = std::distance(textures.begin(), it) + 1; }
    
    for(std::map<Fonts::ID, std::string>::iterator it = fonts.begin(); it != fonts.end(); it++) { sf::Lock lock(mMutex); mFonts.load(it->first, it->second); mFontIndex = std::distance(fonts.begin(), it) + 1; }
    
    { sf::Lock lock(mMutex); mIsFinished = true; }
    
}

void TitleLoadTask::registerAssets() {
    
    textures[Textures::Background] = ".\\files\\textures\\Background.png";
    
    // textures[Textures::TitleScreen] = ".\\files\\textures\\TitleScreen.png";
    // textures[Textures::MenuScreen] = ".\\files\\textures\\MenuScreen.png";
    // textures[Textures::GameModeScreen] = ".\\files\\textures\\GameModeScreen.png";
    // textures[Textures::SettingsScreen] = ".\\files\\textures\\SettingsScreen.png";
    
    // fonts[Fonts::Label] = ".\\files\\fonts\\kenvector_future_thin.ttf";
    
}