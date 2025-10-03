# Simple Text Editor

### Mechanism:
- Type any piece of text in the terminal that gets pushed into an undo stack
- If a user decides to delete pop the the undo stack and push to redo stack
- If a user decides to redo pop the redo stack and push into undo stack

### Commands:
1. type (usage: type "Hello, World!")
2. undo
3. redo
