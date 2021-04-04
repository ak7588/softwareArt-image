# *PAPER TOWNS*

This openFrameworks project simulates the day and the night in a hypothetical city. The image in the centre of the canvas combines several architectural pieces from different cities in the UAE. The style of added architectural pieces -- the houses -- is inspired by the paper town image found on the internet; hence is the name of the project.

![original image with the city](https://github.com/ak7588/softwareArt-image/blob/main/Project%201/bin/data/uae.png)
![paper towns](https://github.com/ak7588/softwareArt-image/blob/main/Project%201/bin/data/paperTowns.jpeg)

## Process

I started off by collecting the colors from the original image and placing them into my color objects in the code. Then, I drew several rectangles and triangles to represent the houses. All of them are placed imperfectly -- and that is made on purpose, to translate the low-fidelity, paper-like style.

![image with extracted colors](https://github.com/ak7588/softwareArt-image/blob/main/Project%201/bin/data/colors.png)

## Code

To get the final result, I have used several calls to the ofRotate() function and played around with object positioning a lot. There is also a GUI element that is the key to displaying the Sun for the day or the Moon for the night.

## Remarks

While I made a significant progress in understanding openFrameworks and the GUI add-on, for the next few steps it would be good to think how can I make a better usage of extracting colors in openFrameworks, pushStyle and popStyle functions, and hardcoding less values into the code.

## Result

![day](https://github.com/ak7588/softwareArt-image/blob/main/Project%201/bin/data/screenshot_000.png)
![night](https://github.com/ak7588/softwareArt-image/blob/main/Project%201/bin/data/screenshot_001.png)
