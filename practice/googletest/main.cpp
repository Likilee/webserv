int multiply(int a, int b) {
    return a * b;
}

int myMax(int a, int b, int c) {
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    return c;
}