bool isPowerOfFour(int n) {
    // Check if power of two AND only the even-position bit is set
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}
