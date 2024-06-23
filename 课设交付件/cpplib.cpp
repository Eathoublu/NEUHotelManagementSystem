#include "iostream"
#include "fstream"
using namespace std;
class room{
private:
    int no[10001] = {0}; //information list.
    int no_index = 0;
    int c1_enmty_num = 200;
    int c1_no[301] = {0};
    int c2_enmty_num = 200;
    int c2_no[301] = {0};
    int c3_enmty_num = 200;
    int c3_no[301] = {0};
    int loader(){
        fstream in("info.txt", ios::in);
        cout<<in.is_open()<<"-is_open-"<<endl;
        if(!in.is_open()){
            return 0;
        }
        int i;
        for(i=0;i<=10000;i++){
            in>>no[i];
        }
        in>>no_index;
        in>>c1_enmty_num;
        for(i=0;i<=200;i++){
            in>>c1_no[i];
        }
        in>>c2_enmty_num;
        for(i=0;i<=200;i++){
            in>>c2_no[i];
        }
        in>>c3_enmty_num;
        for(i=0;i<=200;i++){
            in>>c3_no[i];
        }
        return 0;


    }
    int saver(){
        ofstream out("info.txt", ios::out);
        cout<<out.is_open()<<"-is_open-"<<endl;
        int i;
        for(i=0;i<=10000;i++){
            out<<no[i]<<" ";
        }
        cout<<endl;
        out<<no_index<<endl<<c1_enmty_num<<endl;
        for(i=0;i<=200;i++){
            out<<c1_no[i]<<" ";
        }
        out<<endl;
        out<<c2_enmty_num<<endl;
        for(i=0;i<=200;i++){
            out<<c2_no[i]<<" ";
        }
        out<<endl;
        out<<c3_enmty_num<<endl;
        for(i=0;i<=200;i++){
            out<<c3_no[i]<<" ";
        }
        out<<endl;
        return 0;
    }
public:
    room(){
     //   saver();
        loader();

    };
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
                    saver();
                    return 506;
                }
                //no_index++;

                cout<<"book succeeded with class"<<c<<endl;
                return no_index;
            }else{
                c1_enmty_num = 0;
                cout<<"no more room"<<endl;
                saver();
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
                    saver();
                    return 506;
                }
                cout<<"book succeeded with class"<<c<<endl;
                saver();
                return no_index;
            }else{
                c2_enmty_num = 0;
                cout<<"no more room"<<endl;
                saver();
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
                    saver();
                    return 506;
                }
                cout<<"book succeeded with class"<<c<<endl;
                saver();
                return no_index;
            }else{
                c3_enmty_num = 0;
                cout<<"no more room"<<endl;
                saver();
                return 505;
            }
        }else{
            cout<<"class is not right"<<endl;
            saver();
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
                saver();
                return 505;
            }
            cout<<"has get the room."<<room_num<<endl;
            saver();
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
                saver();
                return 505;
            }
            cout<<"has get the room."<<room_num<<endl;
            saver();
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
                saver();
                return 505;
            }
            cout<<"has get the room."<<room_num<<endl;
            saver();
            return room_num;
        } else {
            cout<<"class is not right!"<<endl;
            saver();
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
            saver();
            return 504;
        }
        saver();
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
                saver();
                return 506;
            }
        }else if(c == 3){
            c3_no[room_num] = 0;
            c1_enmty_num++;
            if(c3_enmty_num>200){
                c3_enmty_num=200;
                saver();
                return 506;
            }
        }else{
            saver();
            return 504;
        }
        saver();
        return 0;
    };
    int get_statistic_c1(){
        saver();
        return c1_enmty_num;
    }
    int get_statistic_c2(){
        saver();
        return c2_enmty_num;
    }
    int get_statistic_c3(){
        saver();
        return c3_enmty_num;
    }

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
//    room Room;
//    cout<<Room.c3_enmty_num;
    return 0;
}