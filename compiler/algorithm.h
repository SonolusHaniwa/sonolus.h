int* rlower_bound(int *L, int *R, int v) {
    int l = 0, r = R - L, res = R - L + 1;
    while (r >= l) {
        int mid = (l + r) / 2;
        if (*(L + mid) <= v) res = mid, l = mid + 1;
        else r = mid - 1;
    } return L + res;
}