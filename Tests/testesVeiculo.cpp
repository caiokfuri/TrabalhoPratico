#include "../Models/Veiculomodel.h"

extern "C" {
    #include "../Munit/munit.h"
}

// Teste do status
static MunitResult test_status(const MunitParameter[], void*) {
    Veiculo v;
    v.setStatus(1);
    munit_assert_int(v.getStatus(), ==, 1);
    return MUNIT_OK;
}

// Teste do localAtual
static MunitResult test_localAtual(const MunitParameter[], void*) {
    Veiculo v;
    v.setLocalAtual("Garagem");
    munit_assert_string_equal(v.getLocalAtual().c_str(), "Garagem");
    return MUNIT_OK;
}

// Teste da placa
static MunitResult test_placa(const MunitParameter[], void*) {
    Veiculo v;
    v.setPlaca("ABC1234");
    munit_assert_string_equal(v.getPlaca().c_str(), "ABC1234");
    return MUNIT_OK;
}

// Teste do modelo
static MunitResult test_modelo(const MunitParameter[], void*) {
    Veiculo v;
    v.setModelo("Fiesta");
    munit_assert_string_equal(v.getModelo().c_str(), "Fiesta");
    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/veiculo/status", test_status, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/veiculo/localAtual", test_localAtual, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/veiculo/placa", test_placa, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/veiculo/modelo", test_modelo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/teste-veiculo", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
