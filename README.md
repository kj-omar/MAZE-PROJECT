# Project Name
**SDL2 Maze Game**

## Introduction
SDL2 Maze Game is a 3D maze adventure built with the SDL2 library using raycasting. Players navigate through a maze while avoiding enemies and collecting items. The project demonstrates core concepts of game development, including input handling, rendering, collision detection, and basic AI for enemies.

- **Deployed Site**: kj-omar.github.io
- **Final Project Blog Article**:https://docs.google.com/document/d/1_VgzM4fBOrI5JxH6ATAxpYSVpEmFTMB8ro-0Y5qkirE/edit?usp=sharing
- **Author's LinkedIn**: (https://www.linkedin.com/in/omar-mihabi-533053279/)

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

Core Features
3D Raycasting Engine: Efficient raycasting algorithm to simulate 3D depth.
Enemy AI: Basic patrol and chase behavior that adds dynamic gameplay.
Weapon System: Players can shoot enemies using a simple firing mechanic.
Textured Walls & Sprites: Use of SDL2_Image for texture loading and applying textures to walls and enemies.
Player Controls: Smooth player movement and rotation through keyboard input.
Challenges & Solutions
1. Implementing Raycasting
Understanding how to project a 3D environment on a 2D plane was the most significant hurdle. The math behind the raycasting algorithm required a deep dive into trigonometry and vector operations. By breaking it down step by step and starting with basic ray-to-wall collision detection, I was able to gradually add texture mapping and perspective correction.

2. Texture Rendering
Getting the textures to map correctly onto the walls required handling various edge cases, such as when rays hit walls at steep angles. I implemented a distance correction technique to avoid visual distortion.

3. Enemy Collision & AI
Making sure that enemies don’t walk through walls or overlap with each other was another challenge. I implemented a basic collision detection system using bounding boxes, ensuring that enemies respect the game’s physics.
