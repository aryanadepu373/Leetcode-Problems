bool uniformArray(int* nums1, int nums1Size) {

    int i, even = 0, odd = 0;

    for(i = 0; i < nums1Size; i++) {

        if(nums1[i] % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }

    if(even == 0 || odd == 0) {
        return true;
    }

    return true;
}