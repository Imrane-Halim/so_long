# So Long And Thanks For All The Fish! 🐬🎮

## Overview
This is a simple 2D game project created as part of a computer graphics course at 1337. The game allows players to control a character, collect items, and escape from a map while avoiding obstacles. The project is built using the MiniLibX graphical library and is written in C.

## Features
- Basic 2D gameplay mechanics 🌟
- Player movement using W, A, S, D keys (or arrow keys) ⬆️⬇️⬅️➡️
- Collectibles to gather 🍣
- A map with walls, free spaces, and an exit 🚪
- Smooth window management 🖥️
- Display of movement count in the shell 📊

## Getting Started
To run the game, you will need to compile the source code. Make sure you have the MiniLibX library installed.

### Prerequisites
- C compiler (gcc) 🛠️
- MiniLibX library

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/so_long.git
   cd so_long
   ```

2. Compile the project using the provided Makefile:
   ```bash
   make
   ```

3. Run the game with a map file:
   ```bash
   ./so_long path/to/map.ber
   ```

## Map Format
The game requires a map file in `.ber` format. The map must consist of:
- `1` for walls 🧱
- `0` for empty spaces 🌌
- `C` for collectibles 🍣
- `E` for the exit 🚪
- `P` for the player's starting position 🐬

### Example Map
```
111111
100001
1C0C01
1P0E01
111111
```

## Acknowledgments
A special shoutout to my friend [Ismail Najah](https://github.com/ismailnajah) for his invaluable help with the player sprite animations. Thank you for your support! 🙌

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For any questions or feedback, feel free to reach out to me via GitHub. 😊