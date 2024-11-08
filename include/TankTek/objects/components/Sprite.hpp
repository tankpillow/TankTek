#ifndef TT_Sprite_HPP_
#define TT_Sprite_HPP_

#include <TankTek/objects/Component.hpp>

#include <vector>

namespace TankTek
{
    class RawModel;
    class Texture;

    class Sprite : public Component
    {
        private: // Utilities
            std::vector<float> vertices;
            std::vector<unsigned int> indices;
            std::vector<float> texCoords;
            TankTek::RawModel* model;
        public:
            Texture* texture;
        public:
            Sprite(GameObject* gameObject);
            ~Sprite();
        public:
            void setTexture(Texture* texture);
        public:
            void onStart() override;
            void onUpdate() override;
            void onRender() override;
            void onStop() override;
        
    };
}

#endif