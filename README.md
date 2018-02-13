# AdSimulation
AdSimulation simulates sending ads to users and keeps track of the information. 
In the user class, it stores a vector of purchased items, and cache of sent ads and clicked ads among other things. 
A container is designed using least recently used (LRU) policy for cache evictions. 

Libraries:
----------
cmake at least 3.9

compile:
----------
1) make sure to update include_directories in CMakeLists.txt. It should point to the project directory.
2) mkdir cmake-build
3) cd cmake-build
4) cmake ..
5) make

Now you can run AdSimulation executable.
