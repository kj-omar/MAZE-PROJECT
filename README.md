# Project Name
**SDL2 Maze Game**

## Introduction
SDL2 Maze Game is a 3D maze adventure built with the SDL2 library using raycasting. Players navigate through a maze while avoiding enemies and collecting items. The project demonstrates core concepts of game development, including input handling, rendering, collision detection, and basic AI for enemies.

- **Deployed Site**: [Link to deployed site]
- **Final Project Blog Article**: [Link to blog article]
- **Author's LinkedIn**: [Your LinkedIn Profile]

## Installation
To run this project locally, follow these steps:

1. Clone the repository:
   git clone https://github.com/kj-omar/MAZE-PROJECT.git
   cd maze-game

2. Install dependencies:
   - Install [SDL2]
   - Install [SDL2_image]

3. Build the project:

   gcc -std=c99 -o sdl_game main.c render.c input.c enemy.c loadTexture.c -lSDL2 -lSDL2_image -lm


4. Run the game:
   ./sdl_game

## Usage
- Use arrow keys to move around.
- Press space to shoot at enemies.
- Your objective is to survive and find the exit.

## Screenshot
![Maze Game Screenshot](path/to/screenshot.png)

## Contributing
If you'd like to contribute to this project:

1. Fork the repository.
2. Create a new feature branch: `git checkout -b feature-branch-name`
3. Commit your changes: `git commit -m 'Add new feature'`
4. Push to the branch: `git push origin feature-branch-name`
5. Open a pull request.

## Related Projects
- [SDL2 Official Documentation](https://wiki.libsdl.org/SDL2)
- [Raycasting in Games](https://lodev.org/cgtutor/raycasting.html)

## Licensing
This project is licensed under the MIT License.
