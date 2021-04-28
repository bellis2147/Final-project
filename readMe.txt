The program is able to initialize the doubly linked list where each node is connected to a singly linked list. The user has the option to add
files, remove files, commit their changes, checkout previous commits, and quit the system. Before being able to use the add function, the user
needs to put their filepath in the filepath string in the miniGit.cpp. The add function is able to take in a new file and add it to the
singly linked list of their current commit. The remove option can then remove a file from the singly linked list of the current commit.
and the linked list is updated to still be connected without leaking any memory. the commit option is makes a new doubly linked list node
and copies the previous linked list to that node. The previous node is still saved and connected to the current commit node. And the checkout
will go back to a previous commit and return the files in that commit. Finally, the user can quit the repository whenever they are done.

-Ben Ellis and Bennett Fragomeni
