cmake_minimum_required(VERSION 3.22)
project(CFinalWork C)

set(CMAKE_C_STANDARD 99)

add_executable(
        CFinalWork
        main.c
        Core/common.c
        Core/common.h
        Core/definition.h
        Core/includes.h
        IO/File.c
        IO/File.h
        IO/Console.c
        IO/Console.h
        Data/CarInfo.h
        Data/Data.c
        Data/Data.h
        UI/UIString.h
        UI/BaseUI.c
        UI/BaseUI.h
        UI/UI.c
        UI/UI.h
        User/Login.c
        User/Login.h
        User/Permission.c
        User/Permission.h
)
