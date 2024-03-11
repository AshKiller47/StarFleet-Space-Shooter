#pragma once

#ifndef STARFLEET_CATEGORY_HPP
#define STARFLEET_CATEGORY_HPP

namespace Category {
    
    enum Type {
        
        None               = 0,
        SceneSpaceLayer    = 1 << 0,
        MasterSpacecraft   = 1 << 1,
        PlayerSpacecraft   = 1 << 2,
        AlliedSpacecraft   = 1 << 3,
        EnemySpacecraft    = 1 << 4,
        AlliedProjectile   = 1 << 5,
        EnemyProjectile    = 1 << 6,
        Pickup             = 1 << 7,
        
        Spacecraft = MasterSpacecraft | PlayerSpacecraft | AlliedSpacecraft | EnemySpacecraft,
        Projectile = AlliedProjectile | EnemyProjectile,
        
        DefenderSpacecraft = PlayerSpacecraft | AlliedSpacecraft
        
    };
    
};

#endif