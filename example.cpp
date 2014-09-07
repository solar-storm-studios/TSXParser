#include <iostream>
#include <TSXParser.h>

int main()
{
    TSX::Parser tsx;

    tsx.load("tmw_desert_spacing.tsx");

    std::cout << "Name: " << tsx.tileset.name << std::endl;
    std::cout << "Tile Width: " << tsx.tileset.tileWidth << std::endl;
    std::cout << "Tile Height: " << tsx.tileset.tileHeight << std::endl;
    std::cout << "Margin: " << tsx.tileset.margin << std::endl;
    std::cout << "Spacing: " << tsx.tileset.spacing << std::endl;
    std::cout << "Tileset Properties:" << std::endl;

    std::map<std::string,std::string>::iterator iter = tsx.tileset.property.begin();
    std::map<std::string,std::string>::iterator end_iter = tsx.tileset.property.end();

    for(; iter != end_iter; ++iter)
    {
        std::cout << "->" << iter->first << " : " << iter->second << std::endl;
    }

    std::cout << "Image Path: " << tsx.tileset.imagePath << std::endl;
    std::cout << "Image Width: " << tsx.tileset.imageWidth << std::endl;
    std::cout << "Image Height: " << tsx.tileset.imageHeight << std::endl;

    for(int i = 0; i < tsx.terrainList.size(); ++i)
    {
        std::cout << "Terrain: " << tsx.terrainList[i].name << " - " << tsx.terrainList[i].tile << std::endl;

        std::map<std::string,std::string>::iterator iter = tsx.terrainList[i].property.begin();
        std::map<std::string,std::string>::iterator end_iter = tsx.terrainList[i].property.end();

        for(; iter != end_iter; ++iter)
        {
            std::cout << "->" << iter->first << " : " << iter->second << std::endl;
        }
    }

    for(int i = 0; i < tsx.tileList.size(); ++i)
    {
        std::cout << "Tile: " << tsx.tileList[i].id << " - ";
        for(int j = 0; j < tsx.tileList[j].terrain.size(); ++j)
        {
            if( j != 0 )
            {
                std::cout << "," << tsx.tileList[i].terrain[j];
            }
            else if (j == tsx.tileList.size())
            {
                std::cout << tsx.tileList[i].terrain[j];
            }
            else
            {
                std::cout << tsx.tileList[i].terrain[j];
            }
        }
        std::cout << std::endl;
        std::map<std::string,std::string>::iterator iter = tsx.tileList[i].property.begin();
        std::map<std::string,std::string>::iterator end_iter = tsx.tileList[i].property.end();

        for(; iter != end_iter; ++iter)
        {
            std::cout << "->" << iter->first << " : " << iter->second << std::endl;
        }
    }
    return 0;
}
