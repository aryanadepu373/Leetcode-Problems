int evalRPN(char** tokens, int tokensSize) {
    int stack[10001],i=0,top=-1;
    while(i<tokensSize){
        if(strcmp(tokens[i],"+")!=0 && strcmp(tokens[i],"-")!=0 && strcmp(tokens[i],"*")!=0 && strcmp(tokens[i],"/")!=0){
            top++;
            stack[top]=atoi(tokens[i]);
        }
        else if(top!=-1){
            int a=stack[top];
            top--;
            int b=stack[top];
            top--;
            int res;
            if(strcmp(tokens[i],"+")==0){
                res=a+b;
                top++;
                stack[top]=res;
            }
            else if(strcmp(tokens[i],"-")==0){
                res=b-a;
                top++;
                stack[top]=res;
            }
            else if(strcmp(tokens[i],"*")==0){
                res=a*b;
                top++;
                stack[top]=res;
            }
            else if(strcmp(tokens[i],"/")==0){
                res=b/a;
                top++;
                stack[top]=res;
            }
        }
        i++;
    }    
    int fres=stack[top];
    return fres;
}