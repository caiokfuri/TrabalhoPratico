#include "../Models/Veiculomodel.h"

extern "C" {
    #include "../Munit/munit.h"
}

static MunitResult test_set_e_get_status(const MunitParameter[], void*) {
    Veiculo v;
    v.setStatus(1);
    munit_assert_int(v.getStatus(), ==, 1);
    return MUNIT_OK;
}

static MunitResult test_set_e_get_localAtual(const MunitParameter[], void*) {
    Veiculo v;
    v.setLocalAtual("Garagem");
    munit_assert_string_equal(v.getLocalAtual().c_str(), "Garagem");
    return MUNIT_OK;
}

static MunitTest tests[] = {
    {(char*)"/veiculo/status", test_set_e_get_status, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/veiculo/localAtual", test_set_e_get_localAtual, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    (char*)"/slem-tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
