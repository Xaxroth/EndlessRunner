# EndlessRunner
Game Demo made by William Michelson

# EndlessRunnerCharacter
Utilizes the base covered by the Third-Person Template in Unreal. The player moves through continuous input in the forward direction (through Tick()), its speed determined by how long the player has spent inside the game. As long as the player is alive, the score variable stored in the GameMode will go up. 

# EndlessRunnerGameMode
The class that contains all the game's crucial data, such as score, lives, speed and conditions. Also handles certain game events such as giving invulnerability frames, and reloading levels.

# InfiniteFloorTile
The base level tile for the game, used as a base for a blueprint class. Planned to automatically move in the player's direction. Destroys itself after a certain distance away from the player by comparing the actors' locations.

# TileSpawner
The trigger that spawns new infinite floor tiles when overlapped by the player character. Spawns tiles at an offset through a CollisionComponent.

# SmallObstacle
The main object class that all objects in the world inherit from apart from the floor tiles. The pickups and hazards are sorted through a switch statement to determine their function. Communicates with the GameMode class upon collision from the player character.
