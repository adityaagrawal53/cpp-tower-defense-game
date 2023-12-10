# Source content
# Enemies
**enemy.hpp/enemy.cpp:** Enemies to be destroyed using towers, they move from checkpoint to checkpoint. If an enemy reaches the end of its path, the player loses 1 LP.

**enemy-plant.hpp/enemy-plant.cpp:** Basic enemy. Deals damage to nearby towers.

**enemy-tree.hpp/enemy.tree.cpp:** Spawns 3 Plant enemies when destroyed.

**enemy-bomb.hpp/enemy-bomb.cpp:** Attacks deal splash damage, damaging nearby towers.

**enemy-boss.hpp/enemy-boss.cpp:** Big enemy with lots of health and deals massive damage.

# Towers
**tower.hpp/tower.cpp:** Towers can attack and destroy nearby enemies. They can be manually placed down by the player.

**tower-plant.hpp/tower-plant.cpp:** Basic tower. Deals damage to nearby enemies.

# Other
**map.hpp/map.cpp:** A grid-based map. Towers can be placed on tiles and enemies move on a predetermined path, depending on map.

**game.hpp/game.cpp/game_loading_functions.cpp:** Handles all interactions between towers and enemies.

**menu.hpp/menu.cpp:** Main menu. Opens on startup, used for starting a game.

**sidemenu.hpp/sidemenu.cpp:** User interface displayed to the side of game.
