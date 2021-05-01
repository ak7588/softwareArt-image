# _Travel Through the Sun_

Demo: 
https://youtu.be/rphaOxsQoXU

![](https://github.com/ak7588/softwareArt-image/blob/main/Project%203/1.png)

### Concept

_Travel Through the Sun_ is an interactive visual and sound experience that immerses the user into a space travel storyline.

The project is made with openFrameworks, with the key inspiration coming from the [music visualizer tutorial](https://www.youtube.com/watch?v=SSEnu6mp7y8&t=276s&ab_channel=danbuzzo) by Dan Buzzo.

![](https://github.com/ak7588/softwareArt-image/blob/main/Project%203/2.png)

### Story

An essential part of the interactive experience is the story told through the colorful Sun animation. The program outputs several sentences that prompt the user to pause and reflect on their feelings:

_How far is the Sun?_
_Scientists say it's 150 million km away._
_But what if you shine just as bright?_
_Then which color is your spark?_

![](https://github.com/ak7588/softwareArt-image/blob/main/Project%203/3.png)

### Shapes and Colors

Shapes are tied to the sound elements used in the piece. In the ofDraw function, there are several variables that control the radius and color intensity of the "Sun" circles by getting the sound spectrum. Then, iterating through each sound band, the circles are drawn based on the aforementioned variables along with the time and sine functions.

![](https://github.com/ak7588/softwareArt-image/blob/main/Project%203/4.png)

### Sound

The sound experience depends on the user input and output. Based on the mouse location, the sound will either speed up or slow down, change volume or tempo.

### Rules

To start the immersive experience, press keys from 1-7. Change the location of the mouse to manipulate the sound or '-'/'=' to change the tempo. To stop the story, press 'a'.

![](https://github.com/ak7588/softwareArt-image/blob/main/Project%203/6.png)

### Reflection

This piece took a lot of experimentation with different ideas, colors, and sounds -- I have started this project thinking that I will implement the story of cell division or flow fields present in the nature. However, after playing around with different visualization methods and sound manipulation, this space travel concept was born. Overall, I feel content with the way it turned out to be, and as a future improvement, I would be interested to see how this piece could be developed into a longer experience.



