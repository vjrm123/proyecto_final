cmake_minimum_required(VERSION 3.26)
project(Proyecto_Final)

# Especifica la ruta de los módulos SDL2
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Encuentra las bibliotecas SDL2, SDL2_image, SDL2_ttf, SDL2_net, SDL2_mixer y SDL2_gfx
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_net REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_gfx REQUIRED)

# Configuración del ejecutable
add_executable(Proyecto_Final main.cpp
        animaciones.h
        avion.h
        bala.h
        balaTipo1.h
        enemigo.h
        enemigo1.h
        enemigo2.h
        general.h
        imagen.h
        misil.h
        musica.h
        proyectil.h
)

# Incluye las cabeceras de las bibliotecas SDL2, SDL2_image, SDL2_ttf, SDL2_net, SDL2_mixer y SDL2_gfx
target_include_directories(Proyecto_Final PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDL2_NET_INCLUDE_DIRS}
        ${SDL2_MIXER_INCLUDE_DIRS}
        ${SDL2_GFX_INCLUDE_DIRS}
)

# Enlaza el ejecutable con las bibliotecas SDL2, SDL2_image, SDL2_ttf, SDL2_net, SDL2_mixer y SDL2_gfx utilizando las targets
target_link_libraries(Proyecto_Final PRIVATE
        SDL2::Core
        SDL2::Main
        SDL2::Image
        SDL2::TTF
        SDL2::Net
        SDL2::Mixer
        SDL2::GFX
)
