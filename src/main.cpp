#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "./map/map.cpp"
#include "./tower/tower.cpp"
#include "./game/game.cpp"
 
int main()
{
   Game game;

   game.run();

   return 0;
}
