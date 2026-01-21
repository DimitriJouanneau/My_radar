MY_RADAR – Air Traffic Control Simulation
Description:

MY_RADAR is an Epitech project consisting of developing a 2D air traffic control panel, in C language, using the CSFML library.

The program simulates the movement of planes between different points, the management of collisions, as well as air traffic control zones represented by control towers.

The entities are loaded from a script passed as an argument, and the simulation is displayed in real time in a graphics window.

Project objectives:

    · Simulate air traffic in 2D
    · Manage planes and control towers
    · Detect and handle collisions
    · Allow certain collisions in control zones
    · User interactions

**Managed entities**
*Airplanes :*

    · Move in a straight line at constant speed
    · Appear after a takeoff delay
    · Disappear upon landing or after a collision
    · 20x20 pixel square hitbox

*Control towers :*

    · Fixes towers
    · Have a circular control zone
    · Allow planes to pass each other without collision

**Simulation script**

The program takes a single argument: the path to a script file describing the entities.

*Format*
Airplane

    · A x_start y_start x_end y_end speed delay

Control tower

    · T x y radius


Fields are separated by spaces or tabs

Example :
A 815 321 1484 166 5 0
A 1589 836 811 936 2 0
A 202 894 103 34 3 0
T 93 47 19
T 49 56 25

**Compilation**

The project is compiled via a Makefile containing the following rules:
```bash
make
make re
make clean
make fclean
```

No binary or temporary files are included in the repository.

**Usage**
Generate a file with all the data of the planes and towers :
```bash
python3 ./generator.py -p 500 -t 10 -r 70 -o scenario.txt
```
| flag  | Description   |
| :--------------- |:---------------:|
| p  |  total number of planes  |
| t  |  total number of towers  |
| r  |  the radius of towers  |
| o  |  send the data to a specific file |
| h  |  for more informations |


Start the simulation
```bash
./my_radar path_to_script
```

Show help
```bash
./my_radar -h
```

**User interactions**

| Touch  | Action   |
| :--------------- |:---------------:|
| l  |  Show / Hide hitboxes  |
| s  |  Show / Hide sprites  |
| ESC  |  Exit the program  |

**Display**

    · Window: 1920x1080
    · Timer displayed in seconds (top right)
    · Sprites for planes and towers (if enabled)
    · Hitboxes and visible areas (if enabled)


📦Project structure
my_radar/
├── include/
├── assets/
├── Makefile
└── src/
     ├── parser/
     ├── aircraft/
     ├── collision/
     ├── core/
     ├── display/
     └── window/

Jouanneau Dimitri
Student at Epitech
