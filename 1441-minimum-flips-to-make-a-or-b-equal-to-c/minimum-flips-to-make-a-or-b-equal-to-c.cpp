class Solution {
public:
    int minFlips(int a, int b, int c) {
        // i copy paste this, bitiwse manipulation is weird
        return popcount<uint>((a | b) ^ c) + popcount<uint>(a & b & ((a | b) ^ c));
    }
};