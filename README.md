cat << 'EOF' > README.md
# Recent EmojiList

A lightweight, rolling-history command built in C. This program tracks unique inputs, manages the emoji list sorting by recent and saves state via a text file.

## Authors & Course Details
* **Course:** PRO101: Computer Fundamentals 
* **Assignment:** Capstone Project
* **Authors:** Aun Ratharanuth, Muny Reach, Sok Somnang, Rith Yousthoninsakd, Heang Sreynin, Kheng Leanghout
* **License:** Copyright (c) 2026. All rights reserved. (Proprietary)

---

## Features
* **Rolling History Queue:** Displays up to 5 of the most recently used emojis.
* **Duplicate Removal:** Automatically detects if an input emoji already exists in history, extracts it, and sents it back to the very front (Index 0).
* **Session Saving:** Seamlessly loads historical states from `history.txt` on startup and saves them back upon clean exit.

---

## System Architecture
The application is structured around a central 2D character array acting as a bounded, sequential memory stack, driven by dynamic array-shifting functions.

## File Structure

The project repository consists of the following components:

- EmojiHistory.c: The core application source file containing all data structures, user input handling, file I/O tracking, and array handling.
- history.txt: The external text database file that is generated and stores the Emoji History list.
- EmojiHistory.exe: The compiled binary executable artifact built specifically for native Windows runtimes.
- README.md: Comprehensive architectural overview, build prerequisites, setup instructions, and deployment guides.

## Program Flow Chart

[Start Program]
│
▼
[Load history.txt] ─── (Populate array & set current_count)
│
▼
┌──────>
│      │
│      ▼
│   [Print Current History Stack]
│      │
│      ▼
│   [Prompt User for Input]
│      │
│      ▼
│   Is Input Valid? ───(No)───> [Print Error / Sleep] ──┐
│      │ (Yes)                                          │
│      ▼                                                │
│   Is Input "exit"? ───(Yes)───> [Save history.txt] ──> [End]
│      │ (No)                                           │
│      ▼                                                │
│   Does Emoji Exist in History?                        │
│      │                                                │
│      ├─────(Yes)─────> [removeDuplicate()]            │
│      ▼                                                │
│   [insertFront()] <───────────────────────────────────┘
│      │
└──────┘

## How to Run

### Prerequisites
You need a C compiler (`gcc` or `clang`) and a standard UNIX terminal terminal runtime framework (Linux/macOS).

### Steps

1. **Clone the Repository** (or open your local project folder):
   ```bash
   cd path/to/your/repository
   
### Compilation
Open your terminal (or MINGW64 bash) and run the following command to compile the source code:

gcc -o EmojiHistory EmojiHistory.c

### Execution
On Windows (MINGW64 / Command Prompt):
./EmojiHistory.exe

On Linux / macOS:
./EmojiHistory
EOF
