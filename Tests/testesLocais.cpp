#include "../Models/Localmodel.h"

extern "C" {
#include "../Munit/munit.h"
}

static MunitResult test_set_e_get_nome(const MunitParameter[], void*) {
    Local l;
    l.setNome("Teste");
    munit_assert_string_equal(l.getNome().c_str(), "Teste");
    return MUNIT_OK;
}

static MunitResult test_set_e_get_x(const MunitParameter[], void*) {
    Local l;
    l.setX(1.0);
    munit_assert_double_equal(l.getX(), 1.0, 2);
    return MUNIT_OK;
}

static MunitResult test_set_e_get_y(const MunitParameter[], void*) {
    Local l;
    l.setY(2.0);
    munit_assert_double_equal(l.getY(), 2.0, 2);
    return MUNIT_OK;
}

// Testes dos construtores
static MunitResult test_construtor_default(const MunitParameter[], void*) {
    Local l;
    munit_assert_string_equal(l.getNome().c_str(), "");
    munit_assert_double_equal(l.getX(), 0.0, 2);
    munit_assert_double_equal(l.getY(), 0.0, 2);
    return MUNIT_OK;
}

static MunitResult test_construtor_parametrizado(const MunitParameter[], void*) {
    Local l("Casa", 10.5, 20.3);
    munit_assert_string_equal(l.getNome().c_str(), "Casa");
    munit_assert_double_equal(l.getX(), 10.5, 2);
    munit_assert_double_equal(l.getY(), 20.3, 2);
    return MUNIT_OK;
}

static MunitResult test_modificacao_sequencial(const MunitParameter[], void*) {
    Local l;

    l.setNome("Local1");
    l.setX(1.0);
    l.setY(2.0);

    munit_assert_string_equal(l.getNome().c_str(), "Local1");
    munit_assert_double_equal(l.getX(), 1.0, 2);
    munit_assert_double_equal(l.getY(), 2.0, 2);

    l.setNome("Local2");
    l.setX(3.0);
    l.setY(4.0);

    munit_assert_string_equal(l.getNome().c_str(), "Local2");
    munit_assert_double_equal(l.getX(), 3.0, 2);
    munit_assert_double_equal(l.getY(), 4.0, 2);

    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/local/nome", test_set_e_get_nome, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/local/x", test_set_e_get_x, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/local/y", test_set_e_get_y, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/local/construtor_default", test_construtor_default, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/local/construtor_parametrizado", test_construtor_parametrizado, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/local/modificacao_sequencial", test_modificacao_sequencial, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/local-tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}