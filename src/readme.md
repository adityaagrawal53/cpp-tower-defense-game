# Source content
# Enemies
**enemy.hpp/enemy.cpp:** Enemies to be destroyed using towers, they move from checkpoint to checkpoint. If an enemy reaches the end of its path, the player loses 1 LP.

#Towers
**tower.hpp/tower.cpp:** Towers can attack and destroy nearby enemies. They can be manually placed down by the player.

#Other
**map.hpp/map.cpp:** A grid-based map. Towers can be placed on tiles and enemies move on a predetermined path, depending on map.

**game.hpp/game.cpp/game_loading_functions.cpp:** Handles all interactions between towers and enemies.
