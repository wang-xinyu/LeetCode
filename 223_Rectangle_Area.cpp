/**
 * Rectangle Area
 *
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long sum = (C-A)*(D-B) + (G-E)*(H-F);
        if (C <= E || A >= G || B >= H || D <= F) return sum;
        sum -= (min(C, G) - max(A, E))*(min(D, H) - max(B, F));
        return sum;
    }
};
