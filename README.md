\# TextRedactor 📝



A lightweight, console-based text editor built from scratch in \*\*C++20\*\* for the Windows environment. It features double-buffered screen rendering via ANSI escape sequences, smart viewport scrolling, and a custom text buffer management engine.



\## Features



\- \*\*Double-Buffered Renderer:\*\* Smooth screen updates that only re-render modified console coordinates to eliminate flickering.

\- \*\*Dynamic Viewport:\*\* Full X and Y scrolling (offsets) supporting documents larger than the current console window size.

\- \*\*Custom Buffer Management:\*\* Robust `TextBuffer` handler managing lines, token insertion, and character erasures.

\- \*\*Native Windows Console Integration:\*\* Uses standard Windows APIs to adjust input processing states for real-time keystroke handling.



\## Architecture \& Project Structure



\- `main.cpp` — Application entry point; initializes the editor session with a target file path.

\- `EditorEngine` — Main loop orchestration, Windows API console mode flags modifier, and keyboard event routing.

\- `InputHandler` — Command patterns translation for arrows, backspace, enter, and text insertion.

\- `ScreenRenderer` — Diff-based console matrix rendering using ANSI escape sequences.

\- `TextBuffer` — Underlying string-vector sequence data structure.

\- `Viewport` — Tracks window dimensions and handles screen scrolling boundaries.



\## Tech Stack



\- \*\*Language:\*\* C++20

\- \*\*Build System:\*\* CMake (Version 4.3 or higher)

\- \*\*OS Platform:\*\* Windows (utilizes `<windows.h>` and `<conio.h>`)



\## Getting Started



\### Prerequisites

Make sure you have a C++20 compatible compiler and CMake installed.



\### Compilation

1\. Clone the repository:

&#x20;  ```bash

&#x20;  git clone https://github.com

&#x20;  cd TermiEdit

&#x20;  ```

2\. Build the project using CMake:

&#x20;  ```bash

&#x20;  mkdir build \&\& cd build

&#x20;  cmake ..

&#x20;  cmake --build .

&#x20;  ```



\### Running the Editor

Run the executable from your terminal by passing a target file path as an argument:

```cmd

TextRedactor.exe path/to/your/file.txt

```



\### Controls

\- \*\*Arrow Keys:\*\* Navigate through the document text.

\- \*\*Enter:\*\* Insert a new line break.

\- \*\*Backspace:\*\* Erase characters or merge adjacent lines.

\- \*\*Ctrl + S (or custom key mapped in code):\*\* Save the document content.



