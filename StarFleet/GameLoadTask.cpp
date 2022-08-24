#include "Game/GameLoadTask.hpp"
#include "ResourceHolder.cpp"

GameLoadTask::GameLoadTask(TextureHolder &textures, FontHolder &fonts): mThread(&GameLoadTask::runTask, this), mTextures(textures), mFonts(fonts), mTextureIndex(0), mFontIndex(0), mIsFinished(false) {
	
	registerAssets();
	
}

void GameLoadTask::execute() {	mIsFinished = false; mThread.launch();	}

bool GameLoadTask::isFinished() {	sf::Lock lock(mMutex); return mIsFinished;	}

std::pair<float, std::string> GameLoadTask::getCompletion() {	sf::Lock lock(mMutex); return std::make_pair((mTextureIndex + mFontIndex) / (float)(textures.size() + fonts.size()), mResource);	}

void GameLoadTask::runTask() {
	
	if(!mTextures.find(textures.begin()->first))
		
		for(std::map<Textures::ID, std::array<std::string, 2>>::iterator it = textures.begin(); it != textures.end(); it++) {
			
			sf::Lock lock(mMutex); mTextures.load(it->first, it->second[0]); mTextureIndex = std::distance(textures.begin(), it) + 1; mResource = it->second[1];
			
		}
	
	else {	sf::Lock lock(mMutex); mTextureIndex = textures.size(); 	}
	
	if(!mFonts.find(fonts.begin()->first))
		
		for(std::map<Fonts::ID, std::array<std::string, 2>>::iterator it = fonts.begin(); it != fonts.end(); it++) {
			
			sf::Lock lock(mMutex); mFonts.load(it->first, it->second[0]); mFontIndex = std::distance(fonts.begin(), it) + 1; mResource = it->second[1];
			
		}
	
	else {	sf::Lock lock(mMutex); mFontIndex = fonts.size(); 	}
	
	{	sf::Lock lock(mMutex); mIsFinished = true;	}
	
}

void GameLoadTask::registerAssets() {
	
	textures[Textures::Enterprise] = {	"build-Release/bin/Assets/Textures/Enterprise.png", "Texture: Enterprise"	};
	textures[Textures::Dauntless] = {	"build-Release/bin/Assets/Textures/Dauntless.png", "Texture: Dauntless"	};
	textures[Textures::Bastion] = {	"build-Release/bin/Assets/Textures/Bastion.png", "Texture: Bastion"	};
	textures[Textures::Anarchy] = {	"build-Release/bin/Assets/Textures/Anarchy.png", "Texture: Anarchy"	};
	textures[Textures::Carnage] = {	"build-Release/bin/Assets/Textures/Carnage.png", "Texture: Carnage"	};
	textures[Textures::Space] = {	"build-Release/bin/Assets/Textures/Space.png", "Texture: Space"	};
	textures[Textures::AlliedBullet] = {	"build-Release/bin/Assets/Textures/AlliedBullet.png", "Texture: AlliedBullet"	};
	textures[Textures::EnemyBullet] = {	"build-Release/bin/Assets/Textures/EnemyBullet.png", "Texture: EnemyBullet"	};
	textures[Textures::Missile] = {	"build-Release/bin/Assets/Textures/Missile.png", "Texture: Missile"	};
	textures[Textures::HealthRefill] = {	"build-Release/bin/Assets/Textures/HealthRefill.png", "Texture: HealthRefill"	};
	textures[Textures::MissileRefill] = {	"build-Release/bin/Assets/Textures/MissileRefill.png", "Texture: MissileRefill"	};
	textures[Textures::FireRate] = {	"build-Release/bin/Assets/Textures/FireRate.png", "Texture: FireRate"	};
	textures[Textures::FireSpread] = {	"build-Release/bin/Assets/Textures/FireSpread.png", "Texture: FireSpread"	};
	
}