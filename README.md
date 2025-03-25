# BataWaf
A C++ implementation of the children's card game with statistical simulation capabilities.

## Game Description
BataWaf is a simple card game for children ages 3+ where players compare dog heights to win cards:

- Deck contains dogs of heights 1 through 6
- All cards are dealt to players at start
- Each round, players reveal their top card
- Player with the tallest dog wins all revealed cards
- Ties ("Bata-Waf!") trigger a face-down/face-up showdown
- Winner collects all cards from the showdown
- Game ends when one player has all the cards

## Simulation Features
- Runs between 1 and 2,147,483,647 game simulations
- Supports 2-4 players
- Tracks rounds needed to complete each game
- Outputs results to CSV showing:
  - Number of rounds
  - Frequency of each round count
- Generates filename with parameters (e.g., btw2p1000g for 2 players, 1000 games)

## How to Use
1. Compile the program:

```bash
make
```

2. Run the simulation:

```bash

./exec
```

3. When prompted, enter:
Number of players (2, 3, or 4)
Number of games to simulate (positive integer)

4. Results will be saved to a CSV file named btw[N]p[M]g where:
[N] = number of players
[M] = number of games

## Example Output
CSV format (rounds,count):

```console
27,2
36,8
48,5
...
```
CSV can then be used for some nice visualisations (here using Numbers app)
<img width="803" alt="Screenshot 2025-03-25 at 09 50 23" src="https://github.com/user-attachments/assets/349c1255-2480-449e-a7d4-ecf6a8b77163" />
<img width="803" alt="Screenshot 2025-03-25 at 09 52 46" src="https://github.com/user-attachments/assets/0edb5790-df3f-4ed9-98c4-03d710e82c7c" />

## Implementation Details

### Core Components
- Game: Manages game state and round logic
- Player: Represents players with their card piles
- Card: Contains dog height values (1-6)
- Deck: Handles card distribution and shuffling

### Key Algorithms
- Recursive round resolution for ties (do_round())
- Statistical tracking using std::map
- CSV output generation

### Requirements
C++17 compatible compiler

## Future Enhancements
- Real-time visualization
- Multi-threaded simulation for large game counts

## Sample Execution
```console
Number of players:
2
Number of games:
1000
Simulation complete. Results saved to btw2p1000g
```

