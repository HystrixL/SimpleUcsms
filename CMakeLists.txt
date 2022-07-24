cmake_minimum_required(VERSION 3.22)
project(CFinalWork C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(./src SRC_FILES)
aux_source_directory(./src/Core CORE_SRC_FILES)
aux_source_directory(./src/Data DATA_SRC_FILES)
aux_source_directory(./src/IO IO_SRC_FILES)
aux_source_directory(./src/UI UI_SRC_FILES)
aux_source_directory(./src/User USER_SRC_FILES)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${CORE_SRC_FILES} ${DATA_SRC_FILES} ${IO_SRC_FILES} ${UI_SRC_FILES} ${USER_SRC_FILES})

add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/Example"
        "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/data"
)