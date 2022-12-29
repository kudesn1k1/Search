#создание исполняемого файла
add_executable(Search Main.cpp)

# добавление каталогов к списку каталогов, в которых компилятор 
# ищет заголовочные файлы, подключаемые директивами #include
include_directories(../google)
include_directories(../src)

#определение подключаемых библиотек Search_lib и gtest
#к заданной цели - исполняемому файлу Search,
#передаваемых компоновщику
target_link_libraries(Search Search_lib gtest)
