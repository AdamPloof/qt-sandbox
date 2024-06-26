set(PROJECT_SOURCES
        main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtModelViewSandbox
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        app.h app.cpp app.ui
        forms/add_expense_form.h forms/add_expense_form.cpp forms/add_expense_form.ui
        service/entity_manager.h service/entity_manager.cpp
        entity/entity_interface.h entity/expense.h entity/expense.cpp
        model/expense_model.h model/expense_model.cpp
    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QtModelViewSandbox APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QtModelViewSandbox SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QtModelViewSandbox
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QtModelViewSandbox PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(QtModelViewSandbox PRIVATE Qt6::Core)
target_link_libraries(QtModelViewSandbox PRIVATE Qt6::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QtModelViewSandbox)
endif()
set_target_properties(QtModelViewSandbox PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QtModelViewSandbox
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtModelViewSandbox)
endif()
