#ifndef TSXPARSER_H
#define TSXPARSER_H

#include <string>
#include <vector>
#include <utility>
#include <map>

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>

namespace TSX {
    class Parser
    {
    public:
        Parser();
        virtual ~Parser();

        bool load(const char* filename);

        struct Tile {
            unsigned int id;
            std::vector<unsigned int> terrain;
            std::map<std::string, std::string> property;
        };

        struct Terrain {
            std::string name;
            unsigned int tile;
            std::map<std::string, std::string> property;
        };

        struct Tileset {
            std::string name;
            std::map<std::string, std::string> property;
            unsigned int tileWidth;
            unsigned int tileHeight;
            unsigned int spacing;
            unsigned int margin;

            std::string imagePath;
            unsigned int imageWidth;
            unsigned int imageHeight;
        };

        Tileset tileset;

        std::vector<Terrain> terrainList;
        std::vector<Tile> tileList;
        //std::vector<unsigned int, std::map<std::string, std::string> tileProperties
    };
}
#endif // TSXPARSER_H
