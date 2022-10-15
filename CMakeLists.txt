cmake_minimum_required(VERSION 3.10.2)

project(Genetic)

add_executable(${PROJECT_NAME}
mainGeneticLearning.cpp
src/Network.cpp
src/Propagation.cpp
src/BackPropagation.cpp
src/Drone.cpp
src/Target.cpp
src/Utils.cpp
src/Actions.cpp
)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

target_link_libraries (${PROJECT_NAME}
	Eigen3::Eigen
	sfml-graphics
	sfml-window
	sfml-system
)
