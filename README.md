# FDF: Wireframe Model

Welcome to FDF, a project where I coded a 3D wireframe renderer entirely from scratch in C. This program transforms a grid of coordinates into a 3D isometric visualization, showcasing landscapes or other shapes in a clean, interactive window. The project was built using the MiniLibX, a lightweight graphical library, and demonstrates core concepts of graphics programming, including rendering, projections, and interactive user controls.

## Features:
- Parses .fdf files containing 3D point data and visualizes them as wireframe models.
- Implements isometric projection for a clear and realistic 3D effect.
- Displays the rendered model in a smooth, interactive window.
- Supports clean exit functionality via keypress or window close button.

## Installation:
1. Clone the repository:

```
git clone https://github.com/your-username/fdf.git  
cd fdf  
```
2. Compile the program using the provided Makefile:
```
make  
```

## Usage:
The program takes an .fdf file as input, which contains a grid of integers. Each number represents a point in 3D space:

- The horizontal position corresponds to the X-axis.
- The vertical position corresponds to the Y-axis.
- The value represents the Z-axis (altitude).

Example of a valid .fdf file:
```
0  0  0  0  0  
0 10 10 10  0  
0 10 20 10  0  
0  0 10  0  0  
```
Run the program:
```
./fdf example.fdf  
```
When you run the program, it opens a window that renders the 3D wireframe model based on the .fdf file's data.

## Key Features
- Graphics Rendering: I implemented a custom rendering engine that calculates and draws the isometric projection of the points.
- Smooth Interaction: The window remains responsive, allowing for smooth interactions like minimizing or switching windows.
- Clean Exit:
  - Press ESC to close the window and quit the program.
  - Alternatively, click the close button on the window frame.
- Memory Safety: All dynamically allocated memory is carefully managed to prevent leaks or crashes.

## Bonus Features:
In addition to the core functionality, I included several enhancements to make the program more interactive and visually appealing:
- Zoom and Translation: Allow zooming in and out of the model, as well as moving it around the window.
- Custom Enhancements: I have implemented my own custom enhancement which I implement after I submitted the project. Instead of using Bresenham's line algorithm which is functional but the lines don't always look smooth, I have instead implemented Xiaolin Wu's line algorithm which renders lines that look smoother. I am still currently changing the code so it still needs some tweaking.

## Technical Details:
- Languages: Written entirely in C.
- Libraries Used:
  - MiniLibX: For graphics rendering.
  - Math Library (-lm): For trigonometric and mathematical calculations.
- File Parsing: I used custom functions, including those from my libft, to efficiently parse .fdf files and handle edge cases.
- Error Handling: The program gracefully handles invalid files and unexpected input.

## Challenges
Building this project taught me a lot about computer graphics, especially:
- How to represent 3D objects in 2D space.
- The math behind isometric projections.
- Efficiently parsing and managing data for rendering.
- Using graphical libraries like MiniLibX for window management and rendering.

## Future Improvements
- Alternative Projections: Parallel and conic projections for different visualization styles.
- Rotation: Rotate the model to view it from different angles.
- Implement shading or lighting for a more realistic 3D effect.
- Add support for dynamically loading new .fdf files without restarting the program.
- Explore additional interaction options, like mouse-based controls.


## About This Project
I developed FDF as part of my journey to learn graphics programming. It represents a significant step forward in understanding how to visualize data in 3D and manage real-time rendering. Every part of this project, from parsing .fdf files to handling graphics in the MiniLibX library, was coded by me, ensuring a deep understanding of the underlying concepts.

## Acknowledgments:
This project is part of the 42 curriculum and serves as an introduction to computer graphics programming. It is a stepping stone to more advanced graphical projects.
