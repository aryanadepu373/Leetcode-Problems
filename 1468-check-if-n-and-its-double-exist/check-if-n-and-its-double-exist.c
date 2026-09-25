bool checkIfExist(int* arr, int arrSize) {
    int i,j;
    for(i=0;i<arrSize;i++){
        for(j=0;j<arrSize;j++){
            if(i!=j && arr[i]==arr[j]*2){
                return true;
            }
        }
    }
    return false;
}