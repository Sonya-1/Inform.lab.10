#ifndef C_H
#define C_H

struct OPERATIONS {
    int plus = 0; // +
    int minus = 0; // -
    int mult = 0; //*
    int div = 0; // /
    int rem = 0; // %
    int eq = 0; // ==
    int less = 0; // <
    int more = 0; // >
    int neq = 0; // !=
    int eqless = 0; // <=
    int eqmore = 0; // >=
    int l_and = 0; // &&
    int l_or = 0; // ||
    int l_not = 0; // !
    int b_and = 0; // &
    int b_or = 0; // |
    int b_not = 0; //~
    int b_xor = 0; // ^
    int lsh = 0; // <<
    int rsh = 0; // >>
    int as = 0; // =
};

bool is_space(char* str, int i);
void count(OPERATIONS* op, char* str, int* rem);
void print_struct(OPERATIONS* op, int* f_len);

#endif