cmake_minimum_required(VERSION 3.31)
project(SLEM_TrabalhoPratico)

set(CMAKE_CXX_STANDARD 26)

add_executable(SLEM_TrabalhoPratico ./main.cpp Models/Localmodel.h Models/PedidoModel.h Models/Veiculomodel.h Munit/munit.c Munit/munit.h Services/EntregaService.cpp Services/EntregaService.h Services/LocalService.cpp Services/LocalService.h Services/PedidoService.cpp Services/PedidoService.h Services/VeiculoService.cpp Services/VeiculoService.h ./cabecalhos.h
)

add_executable(testesVeiculo  Tests/testesVeiculo.cpp  Munit/munit.c  Services/VeiculoService.cpp  Models/Veiculomodel.h)


add_executable(testesLocais Tests/testesLocais.cpp Munit/munit.c Services/LocalService.cpp Models/Localmodel.h)


add_executable(testesPedidos Tests/testePedidos.cpp Munit/munit.c Services/PedidoService.cpp Models/PedidoModel.h)
