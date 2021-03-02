#include <stdio.h>
#include <ctype.h>
#include "struct_count.h"

bool is_space(char* str, int i) {
    if (i < 0) {
        return false;
    }
    char c = str[i];

    if (isspace(c) != 0) {
        return true;
    }
    return false;
}

void count(OPERATIONS* op, char* str, int* rem) {
    int single_qurte = 0, doule_qurte = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '*' && single_qurte == 0 && doule_qurte == 0) {
            if (str[i + 1] == '/') {
                *rem = 0;
                i++;
                continue;
            }
            else if (is_space(str, i - 1) && is_space(str, i + 1)) {
                op->mult++;
            }
            else continue;
        }
        if (*rem == 1) {
            continue;
        }
        if (str[i] == '\'' && doule_qurte == 0) {
            if (single_qurte == 0) {
                single_qurte = 1;
            }
            else {
                single_qurte = 0;
            }
        }
        if (str[i] == '"' && single_qurte == 0) {
            if (doule_qurte == 0) {
                doule_qurte = 1;
            }
            else {
                doule_qurte = 0;
            }
        }
        if (str[i] == '\\') {
            if (doule_qurte == 1 || single_qurte == 1) {
                i++;
                continue;
            }
        }
        if (single_qurte == 1 || doule_qurte == 1) continue;

        if (str[i] == '+') {
            op->plus++;
            if (str[i + 1] == '+') {
                i++;
            }
        }
        if (str[i] == '-') {
            op->minus++;
            if (str[i + 1] == '-') {
                i++;
            }
        }

        if (str[i] == '/') {
            if (str[i + 1] == '/') {
                return;
            }
            else if (str[i + 1] == '*') {
                i++;
                *rem = 1;
            }
            else op->div++;
        }
        if (str[i] == '%') {
            op->rem++;
        }
        if (str[i] == '=') {
            if (str[i + 1] == '=') {
                op->eq++;
                i++;
            }
            else op->as++;
        }
        if (str[i] == '<') {
            if (str[i + 1] == '=') {
                op->eqless++;
                i++;
            }
            else if (str[i + 1] == '<') {
                op->lsh++;
                i++;
            }
            else op->less++;
        }
        if (str[i] == '>') {
            if (str[i + 1] == '=') {
                op->eqmore++;
                i++;
            }
            else if (str[i + 1] == '>') {
                op->rsh++;
                i++;
            }
            else op->more++;
        }
        if (str[i] == '!') {
            if (str[i + 1] == '=') {
                op->neq++;
                i++;
            }
            else op->l_not++;
        }
        if (str[i] == '&') {
            if (str[i + 1] == '&') {
                op->l_and++;
                i++;
            }
            else if (is_space(str, i - 1) && is_space(str, i + 1)) {
                op->b_and++;
            }
            else continue;
        }
        if (str[i] == '|') {
            if (str[i + 1] == '|') {
                op->l_or++;
                i++;
            }
            else op->b_or++;
        }
        if (str[i] == '^') {
            op->b_xor++;
        }
        if (str[i] == '~') {
            op->b_not++;
        }

        if (str[i] == '#') {
            bool fl = false;
            for (int j = 0; j < i; j++) {
                if (!is_space(str, j)) {
                    fl = true;
                    break;
                }
            }
            if (!fl) {
                return;
            }
        }

    }
}

void print_struct(OPERATIONS* op, int* f_len) {
    int math = op->plus + op->minus + op->mult + op->div + op->rem;
    int assignment = op->as;
    int relational = op->eq + op->eqless + op->eqmore + op->neq + op->more + op->less;
    int logical = op->l_and + op->l_or + op->l_not;
    int bitwise = op->b_and + op->b_not + op->b_or + op->lsh + op->rsh + op->b_xor;

    int operations = math + assignment + relational + logical + bitwise;

    if (operations == 0) {
        printf("No operations\n");
        return;
    }

    float m = (float)math / *f_len;
    float a = (float)assignment / *f_len;
    float r = (float)relational / *f_len;
    float l = (float)logical / *f_len;
    float b = (float)bitwise / *f_len;

    printf("Math operations: %f (%i)\n", m, math);
    printf("Assignment operations: %f (%i)\n", a, assignment);
    printf("Relational operations: %f (%i)\n", r, relational);
    printf("Logical operations: %f (%i)\n", l, logical);
    printf("Bitwise operations: %f (%i)\n", b, bitwise);
}
