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
    l.setX(1);
    munit_assert_int(l.getX(), ==, 1);
    return MUNIT_OK;
}

static MunitResult test_set_e_get_y(const MunitParameter[], void*) {
    Local l;
    l.setY(2);
    munit_assert_int(l.getY(), ==, 2);
    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/local/nome", test_set_e_get_nome, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/local/x", test_set_e_get_x, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/local/y", test_set_e_get_y, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};


static const MunitSuite suite = {
    "/local-tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}