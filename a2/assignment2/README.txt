Adam Burke - 20403326, Software Assignment 2

Throughout my coding of the Othello game, I decided to implement the board in such a way that it would print off exactly as shown in the assignment brief. This included using the hyphen ("---") symbols as top dividers and the ("|") symbol as side dividers. Then on the board I also printed out 1 through 8 on the lefthand column in a increasing order, going downwards. As well as the letters A-H on the bottom row in alphabetical order moving to the right.

In terms of the players, I implemented them by using the player struct function. This captured the users name, assinged them a colour, and set there base score equal to two (the starting number of discs on the board for each player).

When it came to the discs I had trouble figuring out how to print out the discs in colours, so I decided to instead, print out the discs with the first letter of their colour scheme, i.e. White = W, Black = B, to represent the placement of the discs on the board.

Game logic was a more tough nut to crack, the hard part was figuring out how to check in moves were valid, this took me a fairly decent amount of time to figure out, but in my playerMoves and my validMoves functions, this was done by checking the squares around the already made moves using the checkDirection boolean function. This then printed out all the valid moves available to each user.