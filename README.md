# OS_8_2019
# INTERACTION OF PROCESSES THROUGH NAMED CHANNELS 
# Tương tác của các tiến trình bằng các kênh có tên (named-pipe - also known as a FIFO)    
## Mục đích bài lab:  
Làm quen với công cụ đồng bộ hóa sử dụng kênh có tên (named-pipe) và các lệnh hệ thống, đảo bảo cho việc tạo (create), mở (open), ghi (write), đọc (read), đóng (close) và xóa (unlink) kênh có tên. 

Việc tạo kênh có tên (named-pipe)bằng lệnh sau:  
`int mkfifo(const char *pathname, mode_t mode),`  
trong đó:  
`pathname` – tên của kênh;  
`mode` – quyền truy cập vào named-pipe.  

Việc mở (open) named-pipe thực hiện bằng lệnh sau:  
`int open(const char *pathname, int flags),`  
trong đó:  
`pathname` – tên của kênh;  
`flags` – flags đặt quyền truy cập vào named-pipe.  

Việc ghi (write) dữ liệu vào named-pipe thực hiện bằng lệnh sau:  
`ssize_t write(int fd, const void *buf, size_t count),`  
trong đó:   
`fd` – descriptor (bộ mô tả) của named-pipe;  
`buf` – buffer (bộ đệm) để ghi dữ liệu;  
`count` – số lượng các dữ liệu được ghi.  

Việc đọc (read) dữ liệu từ named-pipe thực hiện bằng lệnh sau:  
`ssize_t read(int fd, void *buf, size_t count),`  
trong đó:  
`fd` – descriptor (bộ mô tả) của named-pipe;  
`buf` – buffer (bộ đệm) để đọc dữ liệu;  
`count` – kích thước bộ đệm.  

Việc đóng (close) named-pipe thực hiện bằng lệnh sau:  
`int close(int fd)`  
trong đó:  
`fd` - descriptor (bộ mô tả) của named-pipe.  

Việc xóa (unlink) named-pipe thực hiện bằng lệnh sau:  
`int unlink(const char *pathname),`  
trong đó:  
`pathname` - tên của named-pipe  


## Mô tả công việc:  
Tạo bộ 2 chương trình, một để ghi dữ liệu vào named-pipe, một để đọc dữ liệu đó từ named-pipe. Test hàm khi block hoặc không block.
````
//Program 1 
declare a flag to end a thread;
declare a named pipe descriptor;
flow function ()
{
declare a buffer;
yet (the thread termination flag is not set)
{
create a message in the buffer;
write the message from the buffer to the named pipe;
delay for a while;
}
}
main program ()
{
declare a thread id;
create a named pipe;
open named pipe for writing;
create a thread from the thread's function;
wait for key presses;
set the end of thread flag;
wait for the thread to complete;
close the named pipe;
delete named pipe;
}
````
````
//Program2 

declare a flag to end a thread;
declare a named pipe descriptor;
Stream function ()
{
declare a buffer;
yet (the thread termination flag is not set)
{
clear message buffer;
read message from named pipe to buffer;
display a message;
}
}
main program ()
{
declare a thread id;
create a named pipe;
open a named pipe for reading;
create a thread from the thread's function;
wait for key presses;
set the end of thread flag;
wait for the thread to complete;
close the named pipe;
delete named pipe;
}
````




