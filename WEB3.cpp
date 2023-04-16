#include <iostream>
using namespace std;
class car{
    public:
    string make;
    string model;
    int year;
    int speedx;
    int speedy;
    int x;
    int y;
    int length;
    int width;

    void accelerate_in_x(int speedx){
        (this->speedx)=(this->speedx)+ speedx;
    }
    void accelerate_in_y(int speedy){
        this->speedy+=speedy;
    }
    void move(int time){
        (this->x)+=((this->speedx)*time);
        this->y+=((this->speedy)*time);
    }
    
    
};
int detect_collision(car test1, car test2){
        //car1
        float car1_smallx= test1.x;
        float car1_largex= test1.x+test1.length;
        float car1_smally= test1.y;
        float car1_largey= test1.y+test1.width;
        int answer=0;
        if(((test2.x>=car1_smallx)&&(test2.x<=car1_largex))||(((test2.x+test2.length)>=car1_smallx)&&((test2.x+test2.length)<=car1_largex))){
            answer=answer+2;
        }
        if(((test2.y>=car1_smally)&&(test2.y<=car1_largey))||(((test2.y+test2.length)>=car1_smally)&&((test2.y+test2.length)<=car1_largey))){
            answer=answer+3;
        }
        return answer;
        //if(answer==2) cout<<"True"<<endl;
        //else{cout<<"False"<<endl;}
    }
    void time_to_collision(car test1, car test2){
        float time;
        float timex;
        float timey;
        float car1_smallx= test1.x;
        float car1_largex= test1.x+test1.length;
        float car1_smally= test1.y;
        float car1_largey= test1.y+test1.width;
        float car2_smallx= test2.x;
        float car2_largex= test2.x+test2.length;
        float car2_smally= test2.y;
        float car2_largey= test2.y+test2.width;
        float y=detect_collision(test1,test2);
        if(y==0){
            car test1_cpy=test1;
            car test2_cpy=test2;
            //superior in both
            if(car1_smallx>car2_largex&&car1_smally>car2_largey){
                timex=(car1_smallx-car2_largex)/(test2.speedx-test1.speedx);
                timey=(car1_smally-car2_largey)/(test2.speedy-test1.speedy);
                if(timex<0||timey<0){
                    cout<<"They would not collide!!!"<<endl;
                    return;
                }
                else{
                    time=timex>=timey?timex:timey;
                    test1_cpy.y+=(test1_cpy.speedy)*time;
                    test2_cpy.y+=(test1_cpy.speedy)*time;
                    test1_cpy.x+=(test1_cpy.speedx)*time;
                    test2_cpy.x+=(test1_cpy.speedx)*time;
                    if(detect_collision(test1_cpy,test2_cpy)==5){
                        cout<<time<<"hours"<<endl;
                    return;
                    }
                    else{
                        cout<<"NO COLLISION"<<endl;
                        return;
                    }                    
                }

            }
            if(car2_smallx>car1_largex&&car2_smally>car1_largey){
                timex=(car2_smallx-car1_largex)/(test1.speedx-test2.speedx);
                timey=(car2_smally-car1_largey)/(test1.speedy-test2.speedy);
                if(timex<0||timey<0){
                    cout<<"They would not collide!!!"<<endl;
                    return;
                }
                else{
                    time=timex>timey?timex:timey;
                    test1_cpy.y+=(test1_cpy.speedy)*time;
                    test2_cpy.y+=(test1_cpy.speedy)*time;
                    test1_cpy.x+=(test1_cpy.speedx)*time;
                    test2_cpy.x+=(test1_cpy.speedx)*time;
                    if(detect_collision(test1_cpy,test2_cpy)==5){
                        cout<<time<<"hours"<<endl;
                    return;
                    }
                    else{
                        cout<<"NO COLLISION"<<endl;
                        return;
                    }      
                }
            }
            //superior in one
            if(car2_smallx>car1_largex&&car1_smally>car2_largey){
                timex=(car2_smallx-car1_largex)/(test1.speedx-test2.speedx);
                timey=(car1_smally-car2_largey)/(test2.speedy-test1.speedy);
                if(timex<0||timey<0){
                    cout<<"They would not collide!!!"<<endl;
                    return;
                }
                else{
                    time=timex>timey?timex:timey;
                    test1_cpy.y+=(test1_cpy.speedy)*time;
                    test2_cpy.y+=(test1_cpy.speedy)*time;
                    test1_cpy.x+=(test1_cpy.speedx)*time;
                    test2_cpy.x+=(test1_cpy.speedx)*time;
                    if(detect_collision(test1_cpy,test2_cpy)==5){
                        cout<<time<<"hours"<<endl;
                    return;
                    }
                    else{
                        cout<<"NO COLLISION"<<endl;
                        return;
                    }      
                }
            }
            if(car1_smallx>car2_largex&&car2_smally>car1_largey){
                timex=(car1_smallx-car2_largex)/(test2.speedx-test1.speedx);
                timey=(car2_smally-car1_largey)/(test1.speedy-test2.speedy);
                if(timex<0||timey<0){
                    cout<<"They would not collide!!"<<endl;
                    return;
                }
                else{
                    time=timex>timey?timex:timey;
                    test1_cpy.y+=(test1_cpy.speedy)*time;
                    test2_cpy.y+=(test1_cpy.speedy)*time;
                    test1_cpy.x+=(test1_cpy.speedx)*time;
                    test2_cpy.x+=(test1_cpy.speedx)*time;
                    if(detect_collision(test1_cpy,test2_cpy)==5){
                        cout<<time<<"hours"<<endl;
                    return;
                    }
                    else{
                        cout<<"NO COLLISION"<<endl;
                        return;
                    }      
                }
            }

        }
        if(y==2){
            car test1_cpy=test1;
            car test2_cpy=test2;
            float car1=test1.y+test1.width;
            float car2=test2.y+test2.width;
            int car1_samplex,car1_sampley,car2_samplex,car2_sampley;
            float speed= test1.speedy-test2.speedy;
            if(test1.speedy*test2.speedy>0){
                if(test1.speedy>0){
                    
                    if(car1>car2){
                        
                        if(speed>=0){
                            cout<<"They will never collide at this speed "<<endl;
                            return;
                        }
                        else{
                            time=(test1.y-car2)/(speed);
                            //car1_samplex=test1.x+(test1.speedx)*time;
                            //car2_samplex=test2.x+(test2.speedx)*time;
                            test1_cpy.x+=(test1_cpy.speedx)*time;
                            test2_cpy.x+=(test2_cpy.speedx)*time;
                            if(detect_collision(test1_cpy,test2_cpy)==2){
                            cout<<-time<<"hours"<<endl;
                            return;}
                            else {cout<<"NO COLLISION"<<endl;return;}
                            
                        }
                    }
                    else{
                       // int speed= test1.speedy-test2.speedy;
                        if(speed<=0){
                            cout<<"They will never collide at this speed "<<endl;
                            return;
                        }
                        else{
                            time=(test2.y-car1)/(speed);
                            test1_cpy.x+=(test1_cpy.speedx)*time;
                            test2_cpy.x+=(test2_cpy.speedx)*time;
                            if(detect_collision(test1_cpy,test2_cpy)==2){
                            cout<<time<<"hours"<<endl;
                            return;}
                            else {cout<<"NO COLLISION"<<endl;return;}
                        }
                    }
                }
                else{
                    if(test1.speedy<0){
                    
                    if(car1>car2){
                        
                        if(speed>=0){
                            cout<<"They will never collide at this speed "<<endl;
                            return;
                        }
                        else{
                            time=(test1.y-car2)/(speed);
                            test1_cpy.x+=(test1_cpy.speedx)*time;
                            test2_cpy.x+=(test2_cpy.speedx)*time;
                            if(detect_collision(test1_cpy,test2_cpy)==2){
                            cout<<-time<<"hours"<<endl;
                            return;}
                            else {cout<<"NO COLLISION"<<endl;return;}
                        }
                    }
                    else{
                        //int speed= test1.speedy-test2.speedy;
                        if(speed<=0){
                            cout<<"They will never collide at this speed "<<endl;
                            return;
                        }
                        else{
                            time=(test2.y-car1)/(speed);
                             test1_cpy.x+=(test1_cpy.speedx)*time;
                            test2_cpy.x+=(test2_cpy.speedx)*time;
                            if(detect_collision(test1_cpy,test2_cpy)==2){
                            cout<<time<<"hours"<<endl;
                            return;}
                            else {cout<<"NO COLLISION"<<endl;return;}
                           
                        }
                    }
                }
                }
                    
                }
            
            if(test1.speedy*test2.speedy<0){
                if(car1>car2){
                        time=(test1.y-car2)/(test1.speedy+test2.speedy);
                        cout<<time<<"hours"<<endl;
                        return;
                    }
                    if(car2>car1){
                        time=(test2.y-car1)/(test1.speedy+test2.speedy);
                        cout<<time<<"hours"<<endl;
                        return;
                    }
            }
            if(test1.speedy*test2.speedy==0){
                if(test1.speedy==0 && test2.speedy==0){
                    cout<<"Collision will not take place"<<endl;
                    return;
                }
                if(test1.speedy==0){
                    if(car1>car2){
                        if(test2.speedy>0){
                            time=(test1.y-car2)/test2.speedy;
                            cout<<time<<"hours"<<endl;
                            return;
                        }
                        else{
                            cout<<"They will never collide"<<endl;
                            return;
                        }
                    }
                    if(car2>car1){
                        if(test2.speedy<0){
                            time=(test2.y-car1)/test2.speedy;
                            cout<<-time<<"hours"<<endl;
                            return;
                        }
                        else{
                            cout<<"They will never collide"<<endl;
                            return;
                        }
                    }
                    
                }
                if(test2.speedy==0){
                     if(car1>car2){
                        if(test1.speedy<0){
                            time=(test1.y-car2)/test1.speedy;
                            cout<<-time<<"hours"<<endl;
                            return;
                        }
                        else{
                            cout<<"They will never collide"<<endl;
                            return;
                        }
                    }
                    if(car2>car1){
                        if(test1.speedy>0){
                            time=(test2.y-car1)/test1.speedy;
                            cout<<time<<"hours"<<endl;
                            return;
                        }
                        else{
                            cout<<"They will never collide"<<endl;
                            return;
                        }
                    }
                }
            }
        }

        if(y==3){
            car test1_cpy=test1;
            car test2_cpy=test2;
            int car1=test1.x+test1.length;
            int car2=test2.x+test2.length;
            int speed= test1.speedx-test2.speedx;
            if(test1.speedx*test2.speedx>0){
                if(test1.speedx>0){
                    
                    if(car1>car2){
                        
                        if(speed>=0){
                            cout<<"They will never collide at this speed "<<endl;
                            return;
                        }
                        else{
                            time=(test1.x-car2)/(speed);
                            test1_cpy.y+=(test1_cpy.speedy)*time;
                            test2_cpy.y+=(test2_cpy.speedy)*time;
                            if(detect_collision(test1_cpy,test2_cpy)==3){
                            cout<<time<<"hours"<<endl;
                            return;}
                            else {cout<<"NO COLLISION"<<endl;return;}
                        }
                    }
                    else{
                      //  int speed= test1.speedx-test2.speedy;
                        if(speed<=0){
                            cout<<"They will never collide at this speed "<<endl;
                            return;
                        }
                        else{
                            time=(test2.x-car1)/(speed);
                            test1_cpy.y+=(test1_cpy.speedy)*time;
                            test2_cpy.y+=(test2_cpy.speedy)*time;
                            if(detect_collision(test1_cpy,test2_cpy)==3){
                            cout<<time<<"hours"<<endl;
                            return;}
                            else {cout<<"NO COLLISION"<<endl;return;}
                        }
                    }
                }
                else{
                    if(test1.speedx<0){
                    
                    if(car1>car2){
                        
                        if(speed>=0){
                            cout<<"They will never collide at this speed "<<endl;
                            return;
                        }
                        else{
                            time=(test1.x-car2)/(speed);
                            test1_cpy.y+=(test1_cpy.speedy)*time;
                            test2_cpy.y+=(test2_cpy.speedy)*time;
                            if(detect_collision(test1_cpy,test2_cpy)==3){
                            cout<<-time<<"hours"<<endl;
                            return;}
                            else {cout<<"NO COLLISION"<<endl;return;}
                           
                        }
                    }
                    else{
                        //int speed= test1.speedx-test2.speedx;
                        if(speed<=0){
                            cout<<"They will never collide at this speed "<<endl;
                            return;
                        }
                        else{
                            time=(test2.x-car1)/(speed);
                            test1_cpy.y+=(test1_cpy.speedy)*time;
                            test2_cpy.y+=(test2_cpy.speedy)*time;
                            if(detect_collision(test1_cpy,test2_cpy)==3){
                            cout<<time<<"hours"<<endl;
                            return;}
                            else {cout<<"NO COLLISION"<<endl;return;}
                        }
                    }
                }
                }
                    
                }
            
            if(test1.speedx*test2.speedx<0){
                if(car1>car2){
                        time=(test1.x-car2)/(test1.speedx+test2.speedx);
                        cout<<time<<"hours"<<endl;
                        return;
                    }
                    if(car2>car1){
                        time=(test2.x-car1)/(test1.speedx+test2.speedx);
                        cout<<time<<"hours"<<endl;
                        return;
                    }
            }
            if(test1.speedx*test2.speedx==0){
                if(test1.speedx==0 && test2.speedx==0){
                    cout<<"Collision will not take place"<<endl;
                    return;
                }
                if(test1.speedx==0){
                    if(car1>car2){
                        if(test2.speedx>0){
                            time=(test1.x-car2)/test2.speedx;
                            cout<<time<<"hours"<<endl;
                            return;
                        }
                        else{
                            cout<<"They will never collide"<<endl;
                            return;
                        }
                    }
                    if(car2>car1){
                        if(test2.speedx<0){
                            time=(test2.x-car1)/test1.speedx;
                            cout<<-time<<"hours"<<endl;
                            return;
                        }
                        else{
                            cout<<"They will never collide"<<endl;
                            return;
                        }
                    }
                    
                }
                if(test2.speedx==0){
                     if(car1>car2){
                        if(test1.speedx<0){
                            time=(test1.x-car2)/test1.speedx;
                            cout<<-time<<"hours"<<endl;
                            return;
                        }
                        else{
                            cout<<"They will never collide"<<endl;
                            return;
                        }
                    }
                    if(car2>car1){
                        if(test1.speedx>0){
                            time=(test2.x-car1)/test1.speedx;
                            cout<<time<<"hours"<<endl;
                            return;
                        }
                        else{
                            cout<<"They will never collide"<<endl;
                            return;
                        }
                    }
                }
            }

        }
        if(y==5){
            cout<<"Already collided!!!"<<endl;
            return;
        }   
    }

int main(){
    car test1,test2;
    //test2.y=1;
    //test1.x=test1.y=test2.x=test1.speedy=test1.speedx=test2.speedx=test2.speedy=0;
    test1.x=0;
    test1.y=0;
    test2.x=10;
    test2.y=15;
    test1.length=3;
    test1.width=2;
    test2.length=5;
    test2.width=3;
    test1.accelerate_in_x(2);
    test2.accelerate_in_x(-2);
    test1.accelerate_in_y(2);
    test2.accelerate_in_y(1);
    test1.move(3);
    test2.move(2);
   // cout<<test1.x<<endl;
    if(detect_collision(test1,test2)==5)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    time_to_collision(test1,test2);
    
    
    return 0;
}