cmake_minimum_required(VERSION 3.16)
project(i18nKDE)

set(QT_MIN_VERSION "5.15.0")
set(KF5_MIN_VERSION "5.90.0")

set(CMAKE_AUTOUIC ON)    
set(CMAKE_AUTOMOC ON)  
set(CMAKE_AUTORCC ON)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)

find_package(Qt5 ${QT_MIN_VERSION} REQUIRED COMPONENTS Core Widgets)
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS I18n XmlGui ItemModels TextEditor)

include_directories(UI)

file(GLOB UI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/UI/*.ui")

aux_source_directory(./ A)
aux_source_directory(./UI CPP_UI_FILES)

add_executable(i18nKDE ${A} ${UI_FILES} ${CPP_UI_FILES})
target_link_libraries(i18nKDE Qt5::Core Qt5::Widgets KF5::I18n KF5::XmlGui KF5::ItemModels KF5::TextEditor)

# KI18n translation support
ki18n_install(po)

# Optional: Add custom target to update .pot file
find_package(Gettext REQUIRED)
add_custom_target(update-pot
    COMMAND xgettext --language=C++ --keyword=i18n --from-code=UTF-8 --output=po/template.po ${A}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Updating translation template (POT) file"
)