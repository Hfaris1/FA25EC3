# Coding Tree log 

- What I did:
Finished the Tree and Node classes in tree.h.
Added functions like createRoot, addNode, findNode, printAll, and playGame.

- Problems I ran into:
I had a typo in the Tree constructor.
Also forgot to include <limits> for numeric_limits.

- How I fixed it:
Corrected the constructor and added the missing header.

Story parsing
- What I worked on:
Connected the Tree implementation to main.cpp.
Set up testing for the story parsing.
Verified that the tree builds correctly from the parsed nodes.

- Problems I ran into:
The program kept saying “Story was empty or invalid.”
The issue was not with the parsing or tree code, but because the executable was running inside the cmake-build-debug folder and could not find story.txt.
Also needed to clean/rebuild the project since CLion was using an older build.

- How I fixed it:
Moved or referenced story.txt correctly so the program could read it.
Deleted the build folder and rebuilt the project to make sure the updated main.cpp was compiled.

