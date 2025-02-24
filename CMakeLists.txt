cmake_minimum_required(VERSION 3.10)
project(DirectoryBrowser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create templates directory and copy files
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/templates)

# Write template files directly
file(WRITE ${CMAKE_BINARY_DIR}/templates/style.css
"body {
    font-family: Arial, sans-serif;
    margin: 0;
    padding: 20px;
    background: #f5f5f5;
}
header {
    background: #333;
    color: white;
    padding: 1em;
    margin-bottom: 2em;
}
.directory-list {
    background: white;
    padding: 20px;
    border-radius: 5px;
    box-shadow: 0 2px 5px rgba(0,0,0,0.1);
}
table {
    width: 100%;
    border-collapse: collapse;
}
th, td {
    padding: 10px;
    text-align: left;
    border-bottom: 1px solid #ddd;
}
th {
    background: #f5f5f5;
}")

add_executable(directory_browser 
    src/main.cpp
    src/directory_scanner.cpp
    src/html_generator.cpp
)
