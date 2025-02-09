# Deckbuilding Card Game

## Introduction

This project is a personal endeavor to develop a deckbuilding card game using C++. The game combines strategic deck management with engaging gameplay mechanics. Please note that this project is currently a work in progress and may not be completed.

## Features

- **Combat System**: An interactive combat system where players use their decks to battle opponents.
- **Buffs and Effects**: Implementation of various buffs and effects that can alter gameplay dynamics.
- **Enemy AI**: Basic enemy behavior and interactions.
- **Deck Management**: Players can build and customize their decks with various cards.

Until now, there is only one enemy available and player has to type his name in ('Hippie'). Later, the goal is to developp a deckbuilding and roguelike mechanics, where each beaten enemy
drops a card and the player has to build his deck to reach and defeat the Boss Ennemy.

## Project Structure

The project is organized into several components:

- **Card Management**:
  - `Card.cpp` & `Card.hpp`: Define the properties and behaviors of individual cards.
  - `Deck.cpp` & `Deck.hpp`: Manage collections of cards that form a player's deck.
  - `Collection.cpp` & `Collection.hpp`: Handle the overall card collection available to players.

- **Character and Enemy**:
  - `ACharacter.cpp` & `ACharacter.hpp`: Abstract class defining common character attributes and methods.
  - `Enemy.cpp` & `Enemy.hpp`: Specific implementations for enemy characters.
  - `Player.cpp` & `Player.hpp`: Specific implementations for player characters.

- **Effects and Buffs**:
  - `IEffect.hpp`: Interface for game effects.
  - `EffectFactory.cpp` & `EffectFactory.hpp`: Factory for creating effects.
  - `Buff.cpp` & `Buff.hpp`: Define various buffs that can be applied to characters or cards.
  - `BuffFactory.cpp` & `BuffFactory.hpp`: Factory for creating buffs.

- **Game Mechanics**:
  - `FightInstance.cpp` & `FightInstance.hpp`: Manage individual combat encounters.
  - `DamageCalc.cpp` & `DamageCalc.hpp`: Handle damage calculations during combat.

- **Utilities**:
  - `Logger.cpp` & `Logger.hpp`: Logging functionality for debugging and tracking game events.
  - `EventManager.cpp` & `EventManager.hpp`: Manage game events and interactions.

- **Game Control**:
  - `GameController.cpp` & `GameController.hpp`: Oversee the main game loop and state transitions.
  - `GameMediator.cpp` & `GameMediator.hpp`: Facilitate communication between different game components.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- `make` is installed
- Make sure to have the necessary libraries and dependencies installed.

### Compilation

To compile the project, navigate to the project directory and run `make`

### Execution

After compilation, run the executable:

```bash
./CardGame
```

## Contributing

As this is a personal project and currently incomplete, contributions are not being accepted at this time.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

