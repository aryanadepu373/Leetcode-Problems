/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int stack[100001],top=-1;
    int i=0;
    while(i<asteroidsSize){
        if(top==-1){
            top++;
            stack[top]=asteroids[i];
        }
        else{
            if(asteroids[i]<0){
                while(top!=-1 && stack[top]>0 && stack[top]<abs(asteroids[i])){
                    top--;
                }
                if(top==-1){
                    top++;
                    stack[top]=asteroids[i];
                }
                else if(stack[top]==abs(asteroids[i])){
                    top--;
                } 
                else if(stack[top]<0){
                    top++;
                    stack[top]=asteroids[i];
                } 
            }
            else{
                top++;
                stack[top]=asteroids[i];
            }
        }
        i++;
    }
    int *a=malloc(asteroidsSize* sizeof(int));
    if(top!=-1){
        for(i=0;i<=top;i++){
            a[i]=stack[i];
        }
    } 
    *returnSize=top+1;
    return a;
}