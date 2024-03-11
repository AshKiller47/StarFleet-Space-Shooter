#pragma once

#ifndef STARFLEET_RESOURCEHOLDER_HPP
#define STARFLEET_RESOURCEHOLDER_HPP

#include <string>
#include <memory>
#include <map>

template<typename Resource, typename Identifier>
class ResourceHolder {
    
    public:
        
        void load(Identifier, const std::string&);
        
        template<typename Parameter>
        void load(Identifier, const std::string&, const Parameter&);
        
        Resource& get(Identifier);
        const Resource& get(Identifier) const;
        
        bool find(Identifier) const;
        
    private:
        
        void insertResource(Identifier, std::unique_ptr<Resource>&);
        
    private:
        
        std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
        
};

#endif