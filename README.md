# Recent Emoji List

A lightweight, rolling-history command built in C. This program tracks unique inputs, manages the emoji list sorting by recent and saves state via a text file.

## Authors & Course Details
* **Course:** PRO101: Computer Fundamentals 
* **Assignment:** Capstone Project
* **Authors:** Aun Ratharanuth, Muny Reach, Sok Samnang, Rith Yousthoninsakd, Heang Sreynin, Kheng Leanghout
* **License:** Copyright (c) 2026. All rights reserved. (Proprietary)

---

## Features
* **Rolling History Queue:** Displays up to 5 of the most recently used emojis.
* **Duplicate Removal:** Automatically detects if an input emoji already exists in history, extracts it, and sents it back to the very front (Index 0).
* **Session Saving:** Seamlessly loads historical states from `history.txt` on startup and saves them back upon clean exit.

---

## System Architecture
The application is structured around a central 2D character array acting as a bounded, sequential memory stack, driven by dynamic array-shifting functions.
