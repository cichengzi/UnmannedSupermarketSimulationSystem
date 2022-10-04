cmake_minimum_required(VERSION 3.17)
project(UnmannedSupermarketSimulationSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


add_executable(${PROJECT_NAME} main.cpp Commodity.h Commodity.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp CommodityShelf.h CommodityShelf.cpp Supermarket.h Supermarket.cpp User.h User.cpp test.h test.cpp UseCase.h UseCase.cpp ShoppingCart.h ShoppingCart.cpp Helper.h Helper.cpp simulator.cpp simulator.h simulator.ui productpurchase.cpp productpurchase.h productpurchase.ui)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})