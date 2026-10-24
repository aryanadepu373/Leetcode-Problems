int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int hash[13],i;
    for(i=1;i<13;i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
            hash[i]=31;
        }
        else if(i==2){
            hash[i]=28;
        }
        else{
            hash[i]=30;
        }
    }
    for(i=2;i<13;i++){
        hash[i]=hash[i]+hash[i-1];
    }
    int maa,daa;
    sscanf(arriveAlice,"%d-%d",&maa,&daa);
    int mab,dab;
    sscanf(arriveBob,"%d-%d",&mab,&dab);
    int mla,dla;
    sscanf(leaveAlice,"%d-%d",&mla,&dla);
    int mlb,dlb;
    sscanf(leaveBob,"%d-%d",&mlb,&dlb);

    int sday_a=hash[maa-1]+daa;
    int sday_b=hash[mab-1]+dab;
    int eday_a=hash[mla-1]+dla;
    int eday_b=hash[mlb-1]+dlb;

    int maxArrive=0,flag1=0;
    if(sday_a>sday_b){
        maxArrive=sday_a;
        if(maxArrive>=sday_b && maxArrive<=eday_b){
            flag1=1;
        }
    }
    else{
        maxArrive=sday_b;
        if(maxArrive>=sday_b && maxArrive<=eday_b){
            flag1=1;
        }
    }

    int minLeave=0,flag2=0;
    if(flag1==0){
        return 0;
    }
    else{
        if(eday_a<eday_b){
            minLeave=eday_a;
            if(minLeave>=sday_b && minLeave<=eday_b){
                flag2=1;
            }
        }
        else{
            minLeave=eday_b;
            if(minLeave>=sday_a && minLeave<=eday_a){
                flag2=1;
            }
        }
    }

    if(flag2==0){
        return 0;
    }
    return minLeave-maxArrive+1;

}