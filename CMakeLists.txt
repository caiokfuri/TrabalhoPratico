cmake_minimum_required(VERSION 3.31)
project(SLEM_TrabalhoPratico)

set(CMAKE_CXX_STANDARD 26)

add_executable(SLEM_TrabalhoPratico
        ./main.cpp
        ./cabecalhos.h
        Models/Localmodel.h
        Models/PedidoModel.h
        Models/Veiculomodel.h
        Munit/munit.c
        Munit/munit.h
        Services/EntregaService.cpp
        Services/EntregaService.h
        Services/LocalService.cpp
        Services/LocalService.h
        Services/PedidoService.cpp
        Services/PedidoService.h
        Services/VeiculoService.cpp
        Services/VeiculoService.h
        Services/DataService.cpp
        Services/DataService.h
)

add_executable(testesVeiculo
        Tests/testesVeiculo.cpp
        Munit/munit.c
        Services/VeiculoService.cpp
        Services/VeiculoService.h
        Services/PedidoService.cpp
        Services/PedidoService.h
        Services/LocalService.cpp
        Services/LocalService.h
        Services/DataService.cpp
        Services/DataService.h
        Models/Veiculomodel.h
        Models/PedidoModel.h
        Models/Localmodel.h
)

add_executable(testesLocais
        Tests/testesLocais.cpp
        Munit/munit.c
        Services/LocalService.cpp
        Services/LocalService.h
        Services/DataService.cpp
        Services/DataService.h
        Services/PedidoService.cpp
        Services/PedidoService.h
        Services/VeiculoService.cpp
        Services/VeiculoService.h
        Models/Veiculomodel.h
        Models/Localmodel.h
        Models/PedidoModel.h
)

add_executable(testesPedidos
        Tests/testePedidos.cpp
        Munit/munit.c
        Services/PedidoService.cpp
        Services/PedidoService.h
        Services/LocalService.cpp
        Services/LocalService.h
        Services/VeiculoService.cpp
        Services/VeiculoService.h
        Services/DataService.cpp
        Services/DataService.h
        Models/PedidoModel.h
        Models/Localmodel.h
        Models/Veiculomodel.h
)