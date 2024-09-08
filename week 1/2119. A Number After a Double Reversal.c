bool isSameAfterReversals(int num) {
    while (num % 10 == 0 && num != 0)
        return false;

    return true;
}