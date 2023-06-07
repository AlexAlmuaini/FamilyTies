Hello Quinn and Wojciech :)
Here is the readme for our C++ Movie Game
Hope you like it

//Controls
  Player 1:
  
    Keyboard/Mouse:
    >WASD
    >MouseClick - Menu Options and Breaking Locks
    
    Gamepad:
    >Analogue sticks
    >Xbox: B button - Menu Options and Breaking Locks 
  
  Player 2:
     
    Keyboard/Mouse:
    >Arrow Keys
    >MouseClick - Menu Options and Breaking Locks
    
    Gamepad:
    >Analogue sticks
    >Xbox: B button - Menu Options and Breaking Locks 



//BugFixing
  
We have recorded some random bugs over the course of Testing, however none are too serious:
  
In the event that the game doesnt run - and you recive an exit code like (-1073741515)
The bug is something to do with the Audio Module - there's a dll file missing.
  
You'll have to grab the "openal32.dll" file from the bin folder of your SFML install.
Put the file in the top level of the Cmake Folder.
Return to the IDE, RELOAD THE CMAKE, and game should now run :)
(this for some reason would not push to github, and we also discovered that the dll had to be from your own machine)
  
Another bug we've occasinally encountered is that the shader on level 3 sometimes fails.
We've diagnosed this to some sort of OpenGL version problem but don't have a solid fix for it as its pretty random and only affected  one of the Machines used during development.
  
The best thing to do in this scenario is to just try to run it on another machine. There's footage of it working in our Video subission though, so if it really doesnt work then there's evidence there instead.



