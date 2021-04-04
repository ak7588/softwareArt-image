# *PAPER TOWNS*

This openFrameworks project simulates the day and the night in a hypothetical city. The image in the centre of the canvas combines several architectural pieces from different cities in the UAE. The style of added architectural pieces -- the houses -- is inspired by the paper town image found on the internet; hence is the name of the project.

![bin/data/uae.png]

## Process

I started off by collecting the colors from the original image and placing them into my color objects in the code. Then, I drew several rectangles and triangles to represent the houses. All of them are placed imperfectly -- and that is made on purpose, to translate the low-fidelity, paper-like style.

![image]

## Code

To get the final result, I have used several calls to the ofRotate() function and played around with object positioning a lot. There is also a GUI element that is the key to displaying the Sun for the day or the Moon for the night.

## Remarks

While I made a significant progress in understanding openFrameworks and the GUI add-on, for the next few steps it would be good to think how can I make a better usage of extracting colors in openFrameworks, pushStyle and popStyle functions, and hardcoding less values into the code.

## Result

![bin/data/screenshot_000.png]
![bin/data/screenshot_001.png]
