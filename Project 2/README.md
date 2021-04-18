# Project 2: Mario Game

Demo: https://youtu.be/cdQetc7PvUE

## Introduction

It's motion time! For this project, I wanted to play around with pixel manipulation and game animation, so this is how the idea to re-implement the Mario Game was born. Building up from my week 5's sketch, I present this game for the Assignment 2 - Motion.

## Shapes and Color

I started off by taking the Mario Spritesheet and cutting it by pixels to represent motion in four directions -- left, right, up, and down. The color palette was pre-determined by the spritesheet [creators](https://www.pinterest.com/pin/721631540269147334/), so all that was left for me to decide were the GUI design and the background choice. So I went for the pixel art that I found online: [the house](https://www.hiclipart.com/search?clipart=pixel+house), [the background](https://www.freepik.com/premium-vector/pixel-8-bit-game-background-with-ground-cloudy-sky-panorama_3805848.htm), and [the diamond](https://www.pixeldiamondgames.com/logo.png).

## R/Evolution

The "motion" essence of the game is the movement of the spritesheet. After failing to use some of the existing spritesheet add-ons, I decided to tackle this project by creating four different <ofImage> type vectors that loop through each of the Mario's steps in four directions. The key to this was figuring out the following loop-trick:

'''
if (ofGetFrameNum() % speed == 0){
              step = (step + 1) % 4;
}
'''

This block of code iterates through all of the images inside the vector and starts again if the last image was shown.

The rest of this game was figuring out the logic, and mouse/keyboard manipulation for the GUI. I created several functions to load and navigate through different scenes of the game application.

Here is a visual sneak-peek into the game:

- Welcome Page
![welcome image](https://github.com/ak7588/softwareArt-image/blob/main/Project%202/screen_0.png)

- Start of the Game
![welcome image](https://github.com/ak7588/softwareArt-image/blob/main/Project%202/screen_1.png)

- Final Animation
![welcome image](https://github.com/ak7588/softwareArt-image/blob/main/Project%202/screen_2.png)

- End-Game Screen
![welcome image](https://github.com/ak7588/softwareArt-image/blob/main/Project%202/screen_3.png)

## Concept

The application starts with the welcome page that presents the premise of the game to the player. It explains the basic rules and asks the player to "help Mario collect X diamonds". After the diamonds are collected, the game is programmed to loop through the motion that "takes" Mario home. After the animation, the screen displays the ending message.

## Reflections

Overall, this was a fun process of learning C++ logic along with creating some of the motion elements in openFrameworks. I feel like I made a huge jump from my first assignment by learning more theory behind openFrameworks and getting more practice with my sketches. Although this program serves purely for entertainment purposes, I am figuring out how to combine both aesthetics and functionality for my next sketches.
