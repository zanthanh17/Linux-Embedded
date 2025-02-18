#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    const char *filename = "thanh.txt";
    int fd;
    int numb_read, numb_write;
    char buf1[12] = "good\n";

    fd = open(filename, O_WRONLY | O_APPEND);

    if (fd == -1)
    {
        printf("open() thanh.txt failed\n");
    }

    lseek(fd, 0, SEEK_SET);

    write(fd, buf1, strlen(buf1));

    close(fd);

    printf("Done!\n");

    return 0;
}
/*Dữ liệu sẽ xuất hiện ở cuối file. Vì khi mở file với cờ O_APPEND thì tất cả các thao tác ghi file bằng write()
 sẽ luôn diễn ra ở cuối file, bất kể vị trí con trỏ mà ta set trong lệnh lseek() ở đâu chăng nữa.*/
