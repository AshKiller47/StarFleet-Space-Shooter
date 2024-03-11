#pragma once

#ifndef STARFLEET_RESOURCEIDENTIFIERS_HPP
#define STARFLEET_RESOURCEIDENTIFIERS_HPP

namespace sf { class Texture; class Font; }

namespace Textures {
    
    enum ID {
        
        Enterprise,
        Dauntless,
        Bastion,
        Anarchy,
        Carnage,
        Space,
        AlliedBullet,
        EnemyBullet,
        Missile,
        HealthRefill,
        MissileRefill,
        FireRate,
        FireSpread,
        Background
        
    };
    
}

namespace Fonts { enum ID { Main, Statistics }; }

template<typename Resource, typename Identifier> class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

/* namespace Textures {
    
    enum ID {
        
        Enterprise,
        Dauntless,
        Bastion,
        Anarchy,
        Carnage,
        Space,
        AlliedBullet,
        EnemyBullet,
        Missile,
        HealthRefill,
        MissileRefill,
        FireRate,
        FireSpread,
        TitleScreen,
        MenuScreen,
        GameModeScreen,
        SettingsScreen
        
    };
    
} */

// namespace Fonts { enum ID { Main, Label, Statistics }; }

#endif