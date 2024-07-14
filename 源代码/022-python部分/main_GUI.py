# - coding:utf-8 -
from Tkinter import *
from tkMessageBox import *
import ctypes
import os


def ensure_password():
  global x
  global password_str
  if e1.get() == password_str:
      showinfo("东大酒店管理系统", "验证成功！")
      x = 0
      password.destroy()
      return
  showinfo("东大酒店管理系统", "验证失败！请重新输入密码！")
  e1.delete(0, END)
  return

def tk_call_1():
  book_no = room.book(1)
  showinfo("东大酒店管理系统", "预定成功，订单号为：" + str(book_no))
  main_e1.delete(0, END)
  return

def tk_call_2():
  book_no = room.book(2)
  showinfo("东大酒店管理系统", "预定成功，订单号为：" + str(book_no))
  main_e1.delete(0, END)
  return

def tk_call_3():
  book_no = room.book(3)
  showinfo("东大酒店管理系统", "预定成功，订单号为：" + str(book_no))
  main_e1.delete(0, END)
  return

def tk_call_4():
  no = int(main_e1.get())
  main_e1.delete(0, END)
  room_no = room.check_in(no)
  showinfo("东大酒店管理系统", "您的房间号为："+ str(room_no))
  return

def tk_call_5():
  no_room = int(main_e1.get()[:-1])
  room_class = int(main_e1.get()[-1])
  main_e1.delete(0, END)
  status_code = room.check_out(no_room, room_class)
  if str(status_code) == '0':
    showinfo("东大酒店管理系统", "退房成功！")
    return
  showinfo("ERROR", "出现了一个错误，请联系程序员")
  return

def tk_call_6():
  showinfo("房间统计数据：", "标准房间还剩：" + str(room.get_statistic(1)) + "大床房间还剩：" + str(room.get_statistic(2)) + "总统套房还剩：" + str(room.get_statistic(3)) )
  return

def tk_call_7():
  cancel_no = int(main_e1.get())
  main_e1.delete(0, END)
  status_code = room.book_cancel(cancel_no)
  if str(status_code) == '200':
    showinfo("东大酒店管理系统", "取消成功！")
    return
  showinfo("ERROR", "出现了一个错误，请联系程序员")
  return



if __name__ == '__main__':
  x = 1
  password_str = '1234'
  password = Tk()
  password.geometry('+600+300')
  password.title('欢迎使用东大酒店管理系统')
  l1 = Label(password, text='请输入密码：')
  l1.grid(row=0, column=0)
  e1 = Entry(password)
  e1.grid(row=0, column=1)
  b1 = Button(password, text='确认', command=ensure_password)
  b1.grid(row=0, column=2)
  password.mainloop()
  if x == 1:
    exit(0)
  print '验证成功！'
  print str(os.path.realpath(__file__))
  # room = ctypes.cdll.LoadLibrary('/Users/eathoublu/PycharmProjects/022/room.so')
  room = ctypes.cdll.LoadLibrary('room2.so')
  main = Tk()
  main.geometry('+600+300')
  main.title('东大酒店管理系统')
  main_b1 = Button(main, text='预定标准房间', command=tk_call_1)
  main_b2 = Button(main, text='预定大床房间', command=tk_call_2)
  main_b3 = Button(main, text='预定总统套房', command=tk_call_3)
  main_b4 = Button(main, text='入住登记', command=tk_call_4)
  main_b5 = Button(main, text='退房登记', command=tk_call_5)
  main_b6 = Button(main, text='统计数据', command=tk_call_6)
  main_b7 = Button(main, text='取消预定', command=tk_call_7)
  main_e1 = Entry(main)
  main_l1 = Label(main, text='键入订单号（退房请在房号后加上房间类型）：')
  main_l2 = Label(main, text='2018 NEU Eathoublu all right reserved.')
  main_b1.grid(row=1, column=2)
  main_b2.grid(row=1, column=3)
  main_b3.grid(row=1, column=4)
  main_e1.grid(row=2, column=1)
  main_b4.grid(row=2, column=2)
  main_b5.grid(row=2, column=3)
  main_b7.grid(row=2, column=4)
  main_b6.grid(row=3, column=1)
  main_l1.grid(row=2, column=0)
  main_l2.grid(row=4, column=0)
  main.mainloop()






