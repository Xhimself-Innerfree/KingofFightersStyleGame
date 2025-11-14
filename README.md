# Project: King of Fighters Style Game (C++/Cocos2d-x)

This project is a two-player, "King of Fighters" style fighting game created for the "Advanced Programming Design Comprehensive Experiment" course. It is built using **C++** and the **Cocos2d-x** game engine, with a strong focus on object-oriented (OOP) design principles.

The game allows two players to select from different characters and engage in a 1v1 fight. The project was co-developed by Liu Jinxiu (刘瑾修) and Gao Jianyu (高建宇).

## Features

* **Main Menu:** A start screen with options to Start, go to Settings, or Exit.
* **Settings Menu:** Includes a toggle for background music.
* **Character Selection:** A two-player selection screen where each player can choose a unique character.
* **2-Player Combat:** Local multiplayer combat scene with health bars for each player.
* **Attack & Collision:** Frame-based animation for attacks with collision detection to reduce opponent's health.
* **Pause & Game Over:** A pause scene with resume/quit options and a "Game Over" screen that declares the winner (1P or 2P).

## Screenshots

| Main Menu | Character Selection |
| :---: | :---: |
|  |  |
| **Combat Scene** | **Game Over Screen** |
|  |  |

## Technical Design & OOP Structure

The game's architecture is built around the Cocos2d-x engine's `Scene` and `Sprite` framework, with a custom object-oriented design.

### 1. Scene Management

The game flow is managed by transitioning between different `Scene` classes:
* `HelloWorldScene`: The main menu.
* `setting`: The volume control scene.
* `selectcharacter`: The character selection screen.
* `WMJ`: The main combat scene where the fight takes place.
* `Gamepause`: The pause menu.
* `GameOver`: The final screen displaying the winner.

State (like character choice or sound settings) is passed between scenes using global variables (e.t., `bashen1`, `soundflag`, `P1win`).

### 2. Character (Hero) Class Structure

An object-oriented approach was used for the characters, as shown in the UML diagram from the report.


* **`HeroBase` (Abstract Class):** A virtual base class defining the common interface for all characters (e.g., `moveLeft()`, `aclench()`, `standBy()`). It also manages the character's `Sprite` and `EventListener`.
* **`Hero`, `Hero2`, `HeroC` (Concrete Classes):** These classes inherit from `HeroBase`. They provide the specific implementations for each character, such as loading their unique attack animations (sprite frames).

### 3. Key Mechanics Implementation

* **Attack & Input Lock:** To prevent attack animations from being interrupted by mashing keys (a bug found in testing), the `aclench()` function uses a `Sequence` of `CallFunc` actions. When a player attacks:
    1.  The keyboard `listenerKey` is **disabled**.
    2.  The attack animation plays to completion.
    3.  The keyboard `listenerKey` is **re-enabled**.
    This ensures the full animation plays and prevents input spam.

* **Player-Specific Input:** The keyboard listener distinguishes between P1 and P2 controls (e.g., `&& bashen2 == 1`) to ensure that input from one player does not accidentally trigger actions for the other.

* **Win/Loss Logic:** The main combat scene's `update(float dt)` function continuously checks the health variables (`Percentage` and `Percentage2`). When one drops to 0 or below, it sets the appropriate win flag (e.g., `P1win = true`) and transitions to the `GameOver` scene.