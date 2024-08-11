# rubix-cube


**Introduction**

Technology presents us with boundless opportunities, enabling us to explore outer space and simplify our daily lives. It can achieve feats that seem impossible for ordinary humans, such as curing diseases. In this spirit, I will demonstrate how to solve a Rubik’s Cube using advanced technology. This is a fun side project I worked on for a week during the summer of 2024 in order to develop my programming skills.

**Exploring Technological Solutions**

You could learn to solve a Rubik’s Cube through traditional methods, such as memorizing algorithms and developing muscle memory, but that approach is time-consuming. Instead, why not leverage technology to handle this task for us?

**Addressing the Challenge**

One might wonder, "How can you program a robot to solve a Rubik’s Cube if you don’t know how to solve it yourself?" The answer is simple: I don't need to solve the cube personally; instead, I can utilize existing resources and expertise available online. The internet offers numerous libraries and tools created by others, which can be incorporated into my project. Although this approach may seem straightforward, I encountered some challenges along the way.

**Overcoming Obstacles**

Initially, I attempted to use a library that promised to solve the Rubik’s Cube but found it incompatible with the latest version of Python. After some frustration, I soon discovered a more efficient solution by searching extensively online, which led me to a suitable library that met my needs.

**Compiling the Necessary Tools**

To utilize this library, I needed to compile it using Visual Studio Build Tools. For those unfamiliar, these tools provide the necessary environment for compiling code, particularly when dealing with C++ components. Essentially, Visual Studio Build Tools act as a kitchen set, transforming raw code into a functional Python package. Without these tools, compiling would be akin to trying to bake a cake without an oven—resulting in numerous errors and an incomplete project.

**Programming the Solution**

Once the necessary tools were in place, I began programming. The library in question simplifies the Rubik’s Cube solution process. It involves inputting a formatted string representing the cube's colors into a function, which then outputs a series of steps. These steps are parsed and executed to control the robot’s motors.

**Utilizing Computer Vision**

To facilitate the robot’s task, I used computer vision. This involved several steps:

Library Imports: Importing essential libraries such as cv2 (OpenCV), numpy, and imutils.
Image Processing: Loading and processing the image to isolate colors and detect contours.
Color Detection: Defining color ranges and creating masks to identify different colors on the cube.
Contour Analysis: Sorting and grouping contours to determine the cube's color pattern.
Background Removal: Using the Remove.bg API to eliminate background interference from the image.
Serial Communication and Motor Control

With the color detection process complete, the next step involved serial communication with an Arduino to control the motors. The setup includes defining the serial port, baud rate, and timeout. The Arduino program, written to control six servos, listens for commands and moves the servos accordingly. Each command adjusts the angle of the servos to manipulate the Rubik’s Cube.

**Final Thoughts**

While the project faced some challenges, such as dealing with multiple computers and integrating various components, these obstacles are part of the learning experience. In the end it was pretty fun. I still have not connected it to the actual motors yet.
