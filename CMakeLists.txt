cmake_minimum_required(VERSION 3.31)
project(RPG_messAround)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPG_messAround main.cpp
        HP.h
        HP.cpp
        Spell.cpp
        Spell.h
        Monster.cpp
        Monster.h
        Wizard.cpp
        Wizard.h
        RPG_Game.cpp
        declarations.h
)
