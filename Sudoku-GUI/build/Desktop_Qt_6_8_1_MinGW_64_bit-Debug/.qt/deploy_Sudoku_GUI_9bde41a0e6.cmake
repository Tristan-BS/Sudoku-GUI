include(C:/APC/Eigene Programme/C++/Sudoku-GUI/Sudoku-GUI/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/Sudoku-GUI-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/APC/Eigene Programme/C++/Sudoku-GUI/Sudoku-GUI/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/Sudoku-GUI.exe
    GENERATE_QT_CONF
)
