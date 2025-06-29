#include "../Models/PedidoModel.h"
extern "C" {
#include "../Munit/munit.h"
}

// Teste para ID do pedido
static MunitResult test_set_e_get_id(const MunitParameter[], void*) {
    Pedido p;
    p.setId(123);
    munit_assert_int(p.getId(), ==, 123);
    return MUNIT_OK;
}

// Teste para peso do pedido
static MunitResult test_set_e_get_peso(const MunitParameter[], void*) {
    Pedido p;
    p.setPeso(15.5);
    munit_assert_double(p.getPeso(), ==, 15.5);
    return MUNIT_OK;
}

// Teste para local de origem
static MunitResult test_set_e_get_local_origem(const MunitParameter[], void*) {
    Pedido p;
    Local origem;
    origem.setNome("São Paulo");
    origem.setX(10);
    origem.setY(20);

    p.setLocalOrigem(origem);
    Local origemRetornado = p.getLocalOrigem();

    munit_assert_string_equal(origemRetornado.getNome().c_str(), "São Paulo");
    munit_assert_int(origemRetornado.getX(), ==, 10);
    munit_assert_int(origemRetornado.getY(), ==, 20);
    return MUNIT_OK;
}

// Teste para local de destino
static MunitResult test_set_e_get_local_destino(const MunitParameter[], void*) {
    Pedido p;
    Local destino;
    destino.setNome("Rio de Janeiro");
    destino.setX(30);
    destino.setY(40);

    p.setLocalDestino(destino);
    Local destinoRetornado = p.getLocalDestino();

    munit_assert_string_equal(destinoRetornado.getNome().c_str(), "Rio de Janeiro");
    munit_assert_int(destinoRetornado.getX(), ==, 30);
    munit_assert_int(destinoRetornado.getY(), ==, 40);
    return MUNIT_OK;
}

// Teste do construtor padrão
static MunitResult test_construtor_padrao(const MunitParameter[], void*) {
    Pedido p;
    munit_assert_int(p.getId(), ==, 0);
    munit_assert_double(p.getPeso(), ==, 0.0);
    return MUNIT_OK;
}

// Teste do construtor com parâmetros
static MunitResult test_construtor_parametros(const MunitParameter[], void*) {
    Local origem;
    origem.setNome("Origem");
    origem.setX(1);
    origem.setY(2);

    Local destino;
    destino.setNome("Destino");
    destino.setX(3);
    destino.setY(4);

    Pedido p(456, origem, destino, 25.7);

    munit_assert_int(p.getId(), ==, 456);
    munit_assert_double(p.getPeso(), ==, 25.7);

    Local origemRetornado = p.getLocalOrigem();
    Local destinoRetornado = p.getLocalDestino();

    munit_assert_string_equal(origemRetornado.getNome().c_str(), "Origem");
    munit_assert_int(origemRetornado.getX(), ==, 1);
    munit_assert_int(origemRetornado.getY(), ==, 2);

    munit_assert_string_equal(destinoRetornado.getNome().c_str(), "Destino");
    munit_assert_int(destinoRetornado.getX(), ==, 3);
    munit_assert_int(destinoRetornado.getY(), ==, 4);

    return MUNIT_OK;
}

// Teste para valores negativos de ID
static MunitResult test_id_negativo(const MunitParameter[], void*) {
    Pedido p;
    p.setId(-1);
    munit_assert_int(p.getId(), ==, -1);
    return MUNIT_OK;
}

// Teste para peso zero
static MunitResult test_peso_zero(const MunitParameter[], void*) {
    Pedido p;
    p.setPeso(0.0);
    munit_assert_double(p.getPeso(), ==, 0.0);
    return MUNIT_OK;
}

// Teste para modificação de local de origem após criação
static MunitResult test_modificar_origem_depois_criacao(const MunitParameter[], void*) {
    Pedido p;
    Local origem1, origem2;

    origem1.setNome("Primeira Origem");
    origem1.setX(100);
    origem1.setY(200);

    origem2.setNome("Segunda Origem");
    origem2.setX(300);
    origem2.setY(400);

    p.setLocalOrigem(origem1);
    p.setLocalOrigem(origem2);

    Local origemFinal = p.getLocalOrigem();
    munit_assert_string_equal(origemFinal.getNome().c_str(), "Segunda Origem");
    munit_assert_int(origemFinal.getX(), ==, 300);
    munit_assert_int(origemFinal.getY(), ==, 400);

    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/pedido/id", test_set_e_get_id, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/pedido/peso", test_set_e_get_peso, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/pedido/local_origem", test_set_e_get_local_origem, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/pedido/local_destino", test_set_e_get_local_destino, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/pedido/construtor_padrao", test_construtor_padrao, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/pedido/construtor_parametros", test_construtor_parametros, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/pedido/id_negativo", test_id_negativo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/pedido/peso_zero", test_peso_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/pedido/modificar_origem", test_modificar_origem_depois_criacao, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/pedido-tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}