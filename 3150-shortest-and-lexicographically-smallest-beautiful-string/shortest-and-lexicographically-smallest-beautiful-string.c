char* shortestBeautifulSubstring(char* s, int k) {
    int l=0,r=0,count=0,start=-1,minlen=101,len;
    while(s[r]!='\0'){
        if(s[r]=='1'){
            count++;
        }
        while(count>k){
            if(s[l]=='1'){
                count--;
            }
            l++;
        }
        if(count==k){
            while(s[l]=='0'){
                l++;
            }
            len=r-l+1;
            if(len<minlen || (len==minlen && strncmp(s + l, s + start, len) < 0)){
                minlen=len;
                start=l;
            }
        }
        r++;
    }
    if(start==-1){
        char *res=malloc(1);
        res[0]='\0';
        return res;
    }  
    char *res = malloc((minlen+1)* sizeof(char));
    strncpy(res,s+start,minlen);
    res[minlen] = '\0';

    return res;
}