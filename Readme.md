This is a sample case that make catkin build fail.  
It cannot find ROS original include directory.  
It is caused by using `set(CMAKE_CXX_FLAGS "-std=c++11")` instead of `add_compile_options(-std=c++11)`.
