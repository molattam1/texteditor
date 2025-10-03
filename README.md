# Simple Text Editor

A lightweight text editor that runs in the terminal, supporting basic **undo** and **redo** functionality using stack-based operations.

## How It Works

* **Typing:** Any entered text is pushed onto the **undo stack**.
* **Undo:** Removes the latest entry from the **undo stack** and pushes it onto the **redo stack**.
* **Redo:** Retrieves the most recent entry from the **redo stack** and moves it back to the **undo stack**.

This mechanism ensures that you can freely toggle between undoing and redoing changes.

## Commands

* `type` — Enter text to add to the editor.
* `undo` — Revert the last change.
* `redo` — Reapply the last undone change.
* `show` — Display the current state of the text.
* `exit` — Quit the editor.
