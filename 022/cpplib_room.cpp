//
// Created by 蓝一潇 on 2018/5/24.
//
#include "iostream"
using namespace std;
class room{
private:
    int no[10000] = {}; //information list.
    int no_index = 0;
    int c1_enmty_num = 200;
    int c1_no[300] = {0};
//    int c1_index = 1;
//    int c1_total_num = 200;
    int c2_enmty_num = 200;
    int c2_no[300] = {0};
//    int c2_total_num = 200;
//    int c2_index = 1;
    int c3_enmty_num = 200;
    int c3_no[300] = {0};
//    int c3_total_num = 200;
public:
    room(){};
    int book(int c){
        if(c==1){
            c1_enmty_num--;
            if(c1_enmty_num>=0) {
                int i;
                for(i=1;i<=10000;i++){
                    if(no[i]==0){
                        no_index = i;
                        no[no_index] = c;
                        break;
                    }
                }
                if(no_index == 0){
                    return 506;
                }
                //no_index++;

                cout<<"book succeeded with class"<<c<<endl;
                return no_index;
            }else{
                c1_enmty_num = 0;
                cout<<"no more room"<<endl;
                return 505;
            }

        } else if(c == 2){
            c2_enmty_num--;
            if (c2_enmty_num>=0) {
                int i;
                for(i=1;i<=10000;i++){
                    if(no[i]==0){
                        no_index = i;
                        no[no_index] = c;
                        break;
                    }
                }
                if(no_index == 0){
                    return 506;
                }
                cout<<"book succeeded with class"<<c<<endl;
                return no_index;
            }else{
                c2_enmty_num = 0;
                cout<<"no more room"<<endl;
                return 505;
            }
        } else if (c == 3){
            c3_enmty_num--;
            if (c3_enmty_num>=0){
                int i;
                for(i=1;i<=10000;i++){
                    if(no[i]==0){
                        no_index = i;
                        no[no_index] = c;
                        break;
                    }
                }
                if(no_index == 0){
                    return 506;
                }
                cout<<"book succeeded with class"<<c<<endl;
                return no_index;
            }else{
                c3_enmty_num = 0;
                cout<<"no more room"<<endl;
                return 505;
            }
        }else{
            cout<<"class is not right"<<endl;
            return 504;
        }


    };
    int check_in(int index){
        int c;
        c = no[index];
        no[index] = 0;
        if (c == 1){
            int i,room_num = 0;
            for(i=1;i<=200;i++){
                if(c1_no[i]==0){
                    room_num = i;
                    c1_no[i] = 1;
                    break;
                }
            }
            if (room_num==0){
                cout<<"an error has appeared.there's no more room."<<endl;
                return 505;
            }
            cout<<"has get the room."<<room_num<<endl;
            return room_num;

        } else if(c == 2){
            int i,room_num = 0;
            for(i=1;i<=200;i++){
                if(c2_no[i]==0){
                    room_num = i;
                    c2_no[i] = 1;
                    break;
                }
            }
            if (room_num==0){
                cout<<"an error has appeared.there's no more room."<<endl;
                return 505;
            }
            cout<<"has get the room."<<room_num<<endl;
            return room_num;

        } else if(c == 3){
            int i,room_num = 0;
            for(i=1;i<=200;i++){
                if(c3_no[i]==0){
                    room_num = i;
                    c3_no[i] = 1;
                    break;
                }
            }
            if (room_num==0){
                cout<<"an error has appeared.there's no more room."<<endl;
                return 505;
            }
            cout<<"has get the room."<<room_num<<endl;
            return room_num;
        } else {
            cout<<"class is not right!"<<endl;
            return 504;
        }

    };
    int book_cancel(int index){
        int c = no[index];
        if(c == 1){
            no[index] = 0;
            c1_enmty_num++;
            cout<<"book has been canceled!"<<endl;
        }else if(c == 2){
            no[index] = 0;
            c2_enmty_num++;
            cout<<"book has been canceled!"<<endl;
        }else if(c == 3){
            no[index] = 0;
            c3_enmty_num++;
            cout<<"book has been canceled!"<<endl;
        }else{
            cout<<"class error!"<<endl;
            return 504;
        }
        return 200;

    };
    int check_out(int room_num, int c){
        if (c == 1){
            c1_no[room_num] = 0;
            c1_enmty_num++;
            if(c1_enmty_num>200){
                c1_enmty_num=200;
                return 506; //溢出
            }
        }else if(c == 2){
            c2_no[room_num] = 0;
            c1_enmty_num++;
            if(c2_enmty_num>200){
                c2_enmty_num=200;
                return 506;
            }
        }else if(c == 3){
            c3_no[room_num] = 0;
            c1_enmty_num++;
            if(c3_enmty_num>200){
                c3_enmty_num=200;
                return 506;
            }
        }else{
            return 504;
        }
        return 0;
    };
    int get_statistic_c1(){
        return c1_enmty_num;
    }
    int get_statistic_c2(){
        return c2_enmty_num;
    }
    int get_statistic_c3(){
        return c3_enmty_num;
    }

//    int* get_statics_room(int c){
//        int i,index=0;
//        int room[400];
//        if(c == 1) {
//            for (i = 1; i <= 200; i++) {
//                if (c1_no[i]==0){
//                    room[index] = i;
//                    index++;
//                }
//            }
//        }else if(c==2){
//            for (i = 1; i <= 200; i++) {
//                if (c2_no[i]==0){
//                    room[index] = i;
//                    index++;
//                }
//            }
//        }else if(c==3){
//            for (i = 1; i <= 200; i++) {
//                if (c3_no[i]==0){
//                    room[index] = i;
//                    index++;
//                }
//            }
//        }else{
//          //  return 504;
//        }
//        cout<<"empty room number:"<<index<<endl;
//        return room;
//    }

};
extern "C" {
room Room;
int book(int c){
    int info_no = Room.book(c);
    return info_no;
}
int check_in(int index){
    int room_no = Room.check_in(index);
    return room_no;
}
int book_cancel(int index){
    int status_code = Room.book_cancel(index);
    return status_code;
}
int check_out(int room_num, int c){
    int status_code = Room.check_out(room_num, c);
    return status_code;
}
int get_statistic(int c){
    if(c==1){
        return Room.get_statistic_c1();
    }else if(c==2){
        return Room.get_statistic_c2();
    }else if(c==3){
        return Room.get_statistic_c3();
    }else{
        return 504;
    }
}
}
int main(){
    return 0;
}