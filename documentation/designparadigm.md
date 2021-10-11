We think the Project 1 team used a combination of top-down functional decomposition and component level design as their design paradigms. 

From the top down level, there is first the high level design of the battleship game and how it operates. The overall goal is to have a functional game with each player taking their turn, and tracking and updating the game state as necessary. 

The program was broken down into a Player class and an Executive class, with each individual component containing the necessary functions to operate. 

On the component part, the project defined a set of portable, replaceable, and reusable functions (such as checking if a ship was hit using a checkHit() function, placing the ships with a dedicated placeShip() function, etc.) that interfaces with both the player and the executive. These functions are henceforth how each component communicate with one another, through the sets of input and output parameters passed through with each function call. 

Take the board object as an example: a 2d array was chosen as the data structure to represent the board, and the ships are coordinates inside the array. When a ship is placed by the player, the board takes in the row and column values from the executive and communicates with the board to update ship placement, then reports back whether the placement was a success or failure via its return value. 

Through the breakdown of parts using top-down functional decomposition and getting into the nuts and bolts of component level design, it is conceivable that the project 1 team could have utilized the said design paradigms to arrive at their deliverable. 

