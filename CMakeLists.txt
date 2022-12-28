# Проверка версии CMake
# Если версия установленой программы ниже, то ошибка выполнения
cmake_minimum_required(VERSION 3.16)

# Название проекта
project(Search)

# в переменную BINARY_DIR записываем 
#полный путь к каталогу построения проекта верхнего уровня
set(BINARY_DIR "${CMAKE_BINARY_DIR}")

#задание каталога, в который помещается исполняемый файл
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR}/bin")
#задание каталога, в который помещается динамическая библиотека
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BINARY_DIR}/bin")
# задание каталога, в который помещается статическая библиотека 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BINARY_DIR}/lib")

#добавление к построению подпроектов,
#расположенных в заданных подкаталогах
add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(googletest)